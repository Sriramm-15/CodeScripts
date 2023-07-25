// FCFS:
#include<stdio.h>
void main(){
    int bt[20], wt[20], tat[20], i, n;
    float wtavg, tatavg;
    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("\nEnter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i=1;i<n;i++){
        wt[i] = wt[i-1] +bt[i-1];
        tat[i] = tat[i-1] +bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    
printf("\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
for(i=0;i<n;i++) printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i, bt[i], wt[i], tat[i]);
    
    printf("\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f", tatavg/n);
}
// b) sjf
#include<stdio.h>
#include<conio.h>
void main(){
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float wtavg, tatavg;

    printf("\nEnter the number of processes -- ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        p[i]=i;
        printf("Enter Burst Time for Process %d -- ", i);
        scanf("%d", &bt[i]);
    }
    for(i=0;i<n;i++)
        for(k=i+1;k<n;k++)
            if(bt[i]>bt[k]){
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
            }
    wt[0] = wtavg = 0;
    tat[0] = tatavg = bt[0];
    for(i=1;i<n;i++){
        wt[i] = wt[i-1] +bt[i-1];
        tat[i] = tat[i-1] +bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
    for(i=0;i<n;i++) printf("\n\t P%d \t\t %d \t\t %d \t\t %d", p[i], bt[i], wt[i], tat[i]);
    
    printf("\nAverage Waiting Time -- %f", wtavg/n);
    printf("\nAverage Turnaround Time -- %f", tatavg/n);
}
// C) RR:
#include<stdio.h>
void main(){
    int i,j,n,bu[10],wa[10],tat[10],t,ct[10],max;
    float awt=0,att=0,temp=0;

    printf("Enter the no of processes -- ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter Burst Time for process %d -- ", i+1);
        scanf("%d",&bu[i]);
        ct[i]=bu[i];
    }
    printf("\nEnter the size of time slice -- ");
    scanf("%d",&t);
    max=bu[0];
    for(i=1;i<n;i++)
        if(max<bu[i])
            max=bu[i];
    for(j=0;j<(max/t)+1;j++)
        for(i=0;i<n;i++)
        if(bu[i]!=0)
            if(bu[i]<=t){
                tat[i]=temp+bu[i];
                temp=temp+bu[i];
                bu[i]=0;
            }
            else{
                bu[i]=bu[i]-t;
                temp=temp+t;
            }
    for(i=0;i<n;i++){
        wa[i]=tat[i]-ct[i];
        att+=tat[i];
        awt+=wa[i];
    }
    printf("\nThe Average Turnaround time is -- %f",att/n);
    printf("\nThe Average Waiting time is -- %f ",awt/n);
    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
    for(i=0;i<n;i++) printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],wa[i],tat[i]);
}
// D)PRIORITY:
#include<stdio.h>
void main(){
    int p[20],bt[20],pri[20], wt[20],tat[20],i, k, n, temp;
    float wtavg, tatavg;
    printf("Enter the number of processes --- ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        p[i] = i;
        printf("Enter the Burst Time & Priority of Process %d --- ",i);
        scanf("%d %d",&bt[i], &pri[i]);
    }
    for(i=0;i<n;i++)
        for(k=i+1;k<n;k++)
            if(pri[i] > pri[k]){
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=pri[i];
                pri[i]=pri[k];
                pri[k]=temp;
            }
    
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];
    for(i=1;i<n;i++){
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
    for(i=0;i<n;i++) printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],pri[i],bt[i],wt[i],tat[i]);
    printf("\nAverage Waiting Time is --- %f",wtavg/n);
    printf("\nAverage Turnaround Time is --- %f",tatavg/n);
}
// syscall 
//a)
#include <syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc,char * argv[])
    {
        int fd;
        fd=open(argv[1], O_CREAT | O_RDONLY);
        if(fd== -1)
           {
                printf("error opening the file");
           }
        void *buf = (char*) malloc(120);
        int count=read(fd,buf,120);
        printf("count : %d",count);
        printf("%s",buf);
        close(fd);
        int f1;
        f1=open(argv[2],O_CREAT | O_WRONLY);
        if(f1==-1)
           {
                printf("error opening the file");
           }
        int c;
        while(count=read(fd,buf,120)>0)
           {
                c=write(f1,buf,120);
           }
        if(c==-1)
           {
                printf("error writing to the file");
           }
       printf(“\n Successfully copied the content from one file to other”); 
       close(f1);
   }

//b) Program to work with system calls related to directories
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
if(2 != argc)
    {
printf("\n Please pass in the directory name \n");
        return 1;
    }
    DIR *dp = NULL;
    struct dirent *dptr = NULL;
    char buff[128];
memset(buff,0,sizeof(buff));
strcpy(buff,argv[1]);
if(NULL == (dp = opendir(argv[1])) )
    {
printf("\n Cannot open Input directory [%s]\n",argv[1]);
exit(1);
    }
    else{
        if(buff[strlen(buff)-1]=='/')
    {
strncpy(buff+strlen(buff),"newDir/",7);
        }
        else
        {
strncpy(buff+strlen(buff),"/newDir/",8);
        }

printf("\n Creating a new directory [%s]\n",buff);
mkdir(buff,S_IRWXU|S_IRWXG|S_IRWXO);
printf("\n The contents of directory [%s] are as follows \n",argv[1]);
while(NULL != (dptr = readdir(dp)) )
{
printf(" [%s] ",dptr->d_name);
  }
closedir(dp);
rmdir(buff);
printf("\n");
    }

    return 0;
}
//deadlock -----------------------------
#include<stdio.h> 
struct file{
    int all[10]; int max[10]; int need[10]; int flag;
};
void main(){
    struct file f[10]; int fl;
    int i, j, k, p, b, n, r, g, cnt=0, id, newr; int avail[10],
    seq[10];
    printf("Enter number of processes -- "); scanf("%d",&n);
    printf("Enter number of resources -- "); scanf("%d", &r);
    for(i=0;i<n; i++){
        printf("Enter details for P %d", i); printf("\n Enter allocation\t -- \t"); 
        for(j=0;j<r; j++)
            scanf("%d", &f[i].all[j]); 
        printf("Enter Max\t\t -- \t"); 
        for(j=0;j<r; j++) 
            scanf("%d", &f[i].max[j]); 
        f[i].flag=0;
    }
    printf("\n Enter Available Resources\t -- \t"); 
    for(i=0;i<r; i++)
    scanf("%d", &avail[i]);
    printf("\n Enter New Request Details -- ");
    printf("\n Enter pid \t -- \t");
    scanf("%d", &id);
    printf("Enter Request for Resources \t -- \t"); 
    for(i=0;i<r; i++){
        scanf("%d", &newr);
        f[id].all[i] += newr; avail[i]=avail[i] - newr;
    }
    for(i=0;i<n; i++){
        for(j=0;j<r; j++){
            f[i].need[j]=f[i].max[j]-f[i].all[j]; 
            if(f[i].need[j]<0)
                f[i].need[j]=0; 
        } 
    } 
    cnt=0; fl=0; 
    while(cnt!=n){
        g=0;
        for(j=0;j<n; j++){
            if(f[j].flag==0){ 
                b=0;
                for(p=0;p<r; p++){
                    if(avail[p]>=f[j].need[p]) 
                        b=b+1;
                    else 
                        b=b-1;
                }
                if(b==r){
                    printf("\n P %d is visited", j); seq[fl++]=j;
                    f[j].flag=1; 
                    for(k=0;k<r; k++)
                        avail[k]=avail[k]+f[j].all[k]; 
                    cnt=cnt+1;
                    printf("("); 
                    for(k=0;k<r; k++) 
                        printf("%3d",avail[k]);
                    printf(")"); g=1; 
                } 
            } 
        }
        if(g==0){
            printf("\n REQUEST NOT GRANTED -- DEADLOCK OCCURRED");
            printf("\n SYSTEM IS IN UNSAFE STATE"); goto y; 
        } 
    } 
    printf("\n SYSTEM IS IN SAFE STATE");
    printf("\n The Safe Sequence is -- ("); for(i=0;i<fl; i++) printf("P %d ",seq[i]);
    printf(")");
    y: printf("\n Process\t\t Allocation\t\t Max\t\t\t Need\n"); 
    for(i=0;i<n;i++){
        printf("P %d\t", i); 
        for(j=0;j<r; j++) 
            printf("%6d",f[i].all[j]);
        for(j=0;j<r; j++) 
            printf("%6d",f[i].max[j]); 
        for(j=0;j<r; j++) 
            printf("%6d",f[i].need[j]); 
        printf("\n");
    } 
}
//producer consumer
#include<stdio.h>
int main()
{
   int buffer[10], bufsize, in, out, produce, consume, choice=0;
   in = 0;
   out = 0;
   bufsize = 10;
   while(choice !=3)
  {
   printf("\n1. Produce \t 2. Consume \t3. Exit");
   printf("\nEnter your choice: ");
   scanf("%d", &choice);
   switch(choice)
  {
    case 1: 
      if((in+1)%bufsize==out)
      printf("\nBuffer is Full");
      else
    {
     printf("\nEnter the value: ");
     scanf("%d", &produce);
     buffer[in] = produce;
     in = (in+1)%bufsize;
      }
     break;
     case 2: 
        if(in == out)
        printf("\nBuffer is Empty");
        else
      {
        consume = buffer[out];
        printf("\nThe consumed value is %d", consume);
        out = (out+1)%bufsize;
      }
	break;
         }  
      } 
}
/...........................................................
//pipe processing
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
main()
{ 
  int file1,file2;
  int fd;
  char str[256];
  char temp[4]="how";
  char temp1[4];
  file1 = mkfifo("fifo_server",0666); 
  if(file1<0)
   {
  printf("Unable to create a fifo");
  exit(-1);
   }
   file2 = mkfifo("fifo_client",0666);
   if(file2<0) 
   {
   printf("Unable to create a fifo");
   exit(-1);
   }
 printf("fifos server and child created successfuly");
}
............................................................
//fifo
	
//i) Writer Program

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() 
{ 
    int fd;  
    char * myfifo = "/tmp/myfifo"; 
    mkfifo(myfifo, 0666); 
    char arr1[80], arr2[80]; 
    while (1) 
    { 
       fd = open(myfifo, O_WRONLY); 
       fgets(arr2, 80, stdin); 
       write(fd, arr2, strlen(arr2)+1); 
       close(fd); 
       fd = open(myfifo, O_RDONLY);
       read(fd, arr1, sizeof(arr1));  
       printf("User2: %s\n", arr1); 
       close(fd); 
    } 
    return 0; 
}

//ii Reader Program
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main() 
{ 
    int fd1; 
    char * myfifo = "/tmp/myfifo";  
    mkfifo(myfifo, 0666); 
    char str1[80], str2[80]; 
    while (1) 
    {
        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str1, 80); 
        printf("User1: %s\n", str1); 
        close(fd1); 
        fd1 = open(myfifo,O_WRONLY); 
        fgets(str2, 80, stdin); 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
    } 
    return 0; 
}

//message queues
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message; 

int main() 
{ 
    key_t key; 
    int msgid; 
    key = ftok("progfile", 65); 
    msgid = msgget(key, 0666 | IPC_CREAT);  
    msgrcv(msgid, &message, sizeof(message), 1, 0); 
    printf("Data Received is : %s \n",message.mesg_text); 
    msgctl(msgid, IPC_RMID, NULL); 
    return 0; 
}

//d. IPC through shared memory
//i. SHARED MEMORY FOR WRITER PROCESS
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main() 
{ 
   key_t key = ftok("shmfile",65); 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
    char *str = (char*) shmat(shmid,(void*)0,0); 
    cout<<"Write Data : "; 
    gets(str); 
    printf("Data written in memory: %s\n",str); 
    shmdt(str); 
    return 0; 
}

//ii. SHARED MEMORY FOR READER PROCESS

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main() 
{ 
     key_t key = ftok("shmfile",65); 
    int shmid = shmget(key,1024,0666|IPC_CREAT); 
    char *str = (char*) shmat(shmid,(void*)0,0); 
    printf("Data read from memory: %s\n",str); 
    shmdt(str); 
    shmctl(shmid,IPC_RMID,NULL); 
    return 0; 
}
  ......................................
//paging
#include<stdio.h>
#include<conio.h>
main()
{
int ms, ps, nop, np, rempages, i, j, x, y, pa, offset; int s[10], fno[10][20];
printf("\nEnter the memory size -- ");
scanf("%d",&ms);
printf("\nEnter the page size -- ");
scanf("%d",&ps);
nop = ms/ps;
printf("\nThe no. of pages available in memory are -- %d ",nop);
printf("\nEnter number of processes -- ");
scanf("%d",&np);
rempages = nop; for(i=1;i<=np;i++)
{
printf("\nEnter no. of pages required for p[%d]-- ",i);
scanf("%d",&s[i]);
if(s[i] >rempages)
{
printf("\nMemory is Full");
break;
}
rempages = rempages - s[i];
printf("\nEnter pagetable for p[%d] --- ",i);
for(j=0;j<s[i];j++)
scanf("%d",&fno[i][j]);
}
printf("\nEnter Logical Address to find Physical Address ");
printf("\nEnter process no. and pagenumber and offset -- ");
scanf("%d %d %d",&x,&y, &offset);
if(x>np || y>=s[i] || offset>=ps)
printf("\nInvalid Process or Page Number or offset");
else
{
pa=fno[x][y]*ps+offset;
printf("\nThe Physical Address is -- %d",pa);
}
getch();
}

//segmentation
#include<stdio.h>
#include<conio.h>
struct list
{
int seg;
int base;
int limit;
struct list *next;
} *p;
void insert(struct list *q,int base,int limit,int seg)
{
if(p==NULL)
{
p=malloc(sizeof(Struct list));
p->limit=limit;
p->base=base;
p->seg=seg;
p->next=NULL;
}
else
{
while(q->next!=NULL)
{
q=q->next;
Printf("yes")
}
q->next=malloc(sizeof(Struct list));
q->next ->limit=limit;
q->next ->base=base;
q->next ->seg=seg;
q->next->next=NULL;
}}
int find(struct list *q,int seg) {
while(q->seg!=seg)
{
q=q->next;
}
return q->limit;
}
int search(struct list *q,int seg) {
while(q->seg!=seg)
{
q=q->next;
}
return q->base;
}
main() {
p=NULL;
int seg,offset,limit,base,c,s,physical;
printf("Enter segment table\n");
printf("Enter -1 as segment value for termination\n");
do{
printf("Enter segment number");
scanf("%d",&seg);
if(seg!=-1)
{
printf("Enter base value:");
scanf("%d",&base);
printf("Enter value for limit:");
scanf("%d",&limit);
insert(p,base,lmit,seg); }}
while(seg!=-1)
printf("Enter offset:");
scanf("%d",&offset);
printf("Enter bsegmentation number:");
scanf("%d",&seg);
c=find(p,seg);
s=search(p,seg);
if(offset<c) {
physical=s+offset;
printf("Address in physical memory %d\n",physical);
}
else {
printf("error"); 
}
}

