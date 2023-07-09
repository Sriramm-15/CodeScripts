//producer consumer
#include<stdio.h>
#include<stdlib.h>
int mutex = 1, full = 0, empty = 3, x = 0;
int main () {
 int n;
 void producer ();
 void consumer ();
 int wait (int);
 int signal (int);
 printf ("\n1.Producer\n2.Consumer\n3.Exit");
 while (1)
{
 printf ("\nEnter your choice:");
 scanf ("%d", &n);
 switch (n) {
 case 1:
 if ((mutex == 1) && (empty != 0))
 producer ();
 else
 printf ("Buffer is full!!");
 break;
 case 2:
 if ((mutex == 1) && (full != 0))
 consumer ();
 else
 printf ("Buffer is empty!!");
 break;
 case 3:
 exit (0);
 break; }
}
 return 0;
}
int wait (int s)
{
 return (--s);
}
int signal (int s)
{
 return (++s);
}
void producer ()
{
 mutex = wait (mutex);
 full = signal (full);
 empty = wait (empty);
 x++;
 printf ("\nProducer produces the item %d", x);
 mutex = signal (mutex);
}
void consumer ()
{
 mutex = wait (mutex);
 full = wait (full);
 empty = signal (empty);
 printf ("\nConsumer consumes item %d", x);
 x--;
 mutex = signal (mutex);
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
i) Writer Program

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
ii Reader Program
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
Note: Execute the two programs simultaneously
OUTPUT:
User1 :cmrtc
	hyderabad
...........................................
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
Note: Execute the two programs simultaneously
OUTPUT:
Writer side process:
	Write data	: cmrtchyderabad
	Data send is	: cmrtchyderabad
Reader side Process:
	Data received is	: cmrtchyderabad
...................................................................
d. IPC through shared memory
i. SHARED MEMORY FOR WRITER PROCESS
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
ii. SHARED MEMORY FOR READER PROCESS

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
Note: Execute the two programs simultaneously
OUTPUT:
Writer side process:
Write data		: cmrtchyderabad	
Data written in memory	: cmrtchyderabad
Reader side Process:
	Data read from memory	: cmrtchyderabad
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
Printf(“yes”)
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
while(q
->seg!=seg)
{
q=q->next;
}
return q->base;
}
main() {
p=NULL;
int seg,offset,limit,base,c,s,physical;
printf(“Enter segment table\n”);
printf(“Enter -1 as segment value for termination\n”);
do{
printf(“Enter segment number”);
scanf(“%d”,&seg);
if(seg!=-1)
{
printf(“Enter base value:”);
scanf(“%d”,&base);
printf(“Enter value for limit:”);
scanf(“%d”,&limit);
insert(p,base,lmit,seg); }}
while(seg!=-1)
printf(“Enter offset:”);
scanf(“%d”,&offset);
printf(“Enter bsegmentation number:”);
scanf(“%d”,&seg);
c=find(p,seg);
s=search(p,seg);
if(offset<c) {
physical=s+offset;
printf(“Address in physical memory %d\n”,physical);
}
else {
printf(“error”); }

