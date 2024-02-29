import numpy as np
import matplotlib.pyplot as plt

#dictionary
d = dict()
dtx =dict()
packetloss=dict()
throughput=dict()
rxpower=dict()
txpower=dict()
word = "RX"
wordtx ="TX"
checker = 0#gia na metraei se pia 8esi eimaste oste na checkaroyme to dst
rxsum = 0
maxtime=0
txsum = 0

with open(r"C:\Users\User\Documents\test6.txt", 'r') as f:#diabasma arxeioy to r stin arxi einai aparaitito
    for line in f:#epanalipsi gia oles tis grames
        checker = 0 #kanoyme ton checker restart
        words = line.split()#xorismos le3eon se split
        for i in words:#check oles tis le3eis mesa sto words
            if checker >0:#pros8esi checker gia oso einai megalitero toy 0 (kako implement)
                checker = checker + 1
            if checker == 12:#stin 8esi 12 einai to ID toy DST
                #print (i)#debug
                #print ('test1')
                if i in d:#i= le3i poy diabazoyme tora an yparxei +1 alios else
                    d[i] = d[i] + 1
                else:#add stin lista me ari8mo 1
                    d[i] = 1
            if(i==word):#ean i le3i einai rx tote o checker ginete 1 ara mpenoyme sto checker>0 kai metrame(kako implement)
                checker = checker +1
                rxsum += 1
                #print (checker)#debug
                #print ("test2")
#for key in list(d.keys()):#bug gia sbisimo kanei tin epanalipsi ^2
print("times toy DST se ola ta rx einai")
print("________________________")
for key in list(d.keys()):
    print("|ID ",key, ":", d[key],"|")
print("________________________")
#print("rx sum: ",rxsum)#debug gia throughput
with open(r"C:\Users\User\Documents\test5.txt", 'r') as f:
    for line in f:
        checker = 0
        words=line.split()
        for i in words:
            if checker >0:#pros8esi checker gia oso einai megalitero toy 0 (kako implement)
                checker = checker + 1
            if checker == 12:#stin 8esi 12 einai to ID toy DST
                
                    #print (i)#debug
                    #print ('test1')
                if i in dtx:#i= le3i poy diabazoyme tora an yparxei +1 alios else
                    dtx[i] = dtx[i] + 1
                else:#add stin lista me ari8mo 1
                    dtx[i] = 1
            if checker == 14:
                timetester=float(i)
                if maxtime<timetester:
                    maxtime = float(i)
            if(i==wordtx):#ean i le3i einai rx tote o checker ginete 1 ara mpenoyme sto checker>0 kai metrame(kako implement)
                checker = checker +1
                txsum += txsum
for key in list(dtx.keys()):
    print (key,' : ',dtx[key])
for key in list(d.keys()):
    packetloss[key]=1-d[key]/dtx[key]#ypologizoyme gia ola ta entrys to packetloss
    print ("id",key,"value",packetloss[key])
    throughput[key]=  d[key]/maxtime
for key in list(throughput.keys()):
    print ("key :" ,key,"throughput: ",throughput[key])#throughput se olo
print ("power consuption for tx 10 and rx 5 ")
for key in list(d.keys()):
    txpower[key] = dtx[key] * 10
    rxpower[key] = d[key]*5
    print ("dst : ", key ,"tx power : ", txpower[key], "rx power :",rxpower[key] )
    
    
    
ids = list(d.keys())#pername ola ta ids stin ids
values = list(d.values())#pername ola ta values stin values
fig = plt.figure(figsize = (15, 7))#poso megalo 8a einai to plot/episis proto figure gia rx se id
plt.bar(ids, values, color ='maroon',
        width = 0.4)#xroma kai width mparon
plt.xlabel("ids")
plt.ylabel("apperances")
plt.title("id apperances in rx ")
#plt.show()#ena show gia di3i kai ta dyo mazi
ids = list(packetloss.keys())#episis deytero figure opos proto gia packetloss
values = list(packetloss.values())
fig = plt.figure(figsize = (15, 7))
plt.bar(ids, values, color ='maroon',
        width = 0.4)#xroma kai width mparon
plt.xlabel("ids")
plt.ylabel("pl")
plt.title("id pl in rx ")
ids = list(throughput.keys())#episis trito figure gia throughput opos proto gia packetloss
values = list(throughput.values())
fig = plt.figure(figsize = (15, 7))
plt.bar(ids, values, color ='maroon',
        width = 0.4)#xroma kai width mparon
plt.xlabel("ids")
plt.ylabel("throughput")
plt.title("id throughput ")
ids = list(rxpower.keys())#episis trito figure gia throughput opos proto gia packetloss
values = list(rxpower.values())
values2 =list(txpower.values())
fig = plt.figure(figsize = (15, 7))
plt.bar(ids, values, color ='r',
        width = 0.4,align="edge")#xroma kai width mparon
plt.bar (ids,values2,color='b',width=-0.4,align='edge')#negative width for edge to go left
plt.xlabel("ids")
plt.ylabel("power")
plt.title("power ")


plt.show()


