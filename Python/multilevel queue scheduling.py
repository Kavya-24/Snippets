n = int(input("Enter the number of processes : "))
#print(n)
p = [0] * n
bt = [0] * n
wt = [0] * n
tat = [0] * n
su = [0] * n
for i in range(n):
    p[i] = i+1
    bt[i] = int(input("Enter the burst time for process " + str(i+1) + ": "))
    su[i] = int(input("System/User process (0/1) ? "))

for i in range(n):
    for j in range(i+1, n):
        if su[i] > su[j]:
            p[i], p[j] = p[j], p[i]
            bt[i], bt[j] = bt[j], bt[i]
            su[i], su[j] = su[j], su[i]

wtavg = 0
tatavg = 0

for i in range(1, n):
    wt[i] = wt[i-1] + bt[i-1]
    tat[i] = tat[i-1] + bt[i]
    wtavg += wt[i]
    tatavg += tat[i]

print("PROCESS\tSYSTEM/USER PROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n")

for i in range(n):
    print(str(p[i]) + "\t\t" + str(su[i]) + "\t\t" + str(bt[i]) + "\t\t" + str(wt[i]) + "\t\t" + str(tat[i]))

