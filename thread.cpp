module;
#include <arpa/inet.h>  //inet_addr define
#include <stdio.h>  //printf()
#include <sys/socket.h> //socket(), connect(), bind(), listen(), accept(), select(); 
#include <unistd.h>  //close(), fread()
#include <string>  //string type
#include <map>
#include <cstring>
//#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <typeinfo>
#include <ext/stdio_filebuf.h>
#include <fstream>
//export module peer;
//using namespace std;
export module thread;

import peer;

//export std::ofstream out("/dev/stdout");
//export std::ifstream in("/dev/stdin");


#define MAXLINE 1024
#define PORT 3111 
//наследование функции гены мужчина
//pthread_t tid[256];


typedef std::map<int,char*> nmap;
/*enum PeerType{
        _Server,
        _Client
};*/
//char s[80];
/*struct arg{
        std::thread tid;
        int x;
        char y[256];
        enum PeerType isServer;
};*/
/*namespace fix{
struct arg{
        pthread_t tid;
        int x;
        char y[256];
        enum PeerType isServer;
};
};
*/
typedef struct arg args;
//args ar[256]={};
//args *pclient;
//std::queue<args*> qq;
//struct sockaddr_in addr;
/*namespace fix{
typedef struct arg args;
args ar[256]={};
args *pclient;
std::queue<args*> qq;
struct sockaddr_in addr;
};
*/


	//Client * peer = new Server;
	void run(auto *peer);
//enum PeerType isserver=_Server;
/*
struct node{
        struct node *next;
        args *ar;

};
`
typedef struct node node_t;
//typedef struct arg args;
node_t * head = NULL;
node_t * tail = NULL;
void enqueue(args * ar){
node_t * newnode = malloc(sizeof(node_t));
newnode->ar = ar;
newnode->next=NULL;
if(tail==NULL){
head=newnode;
}else{
tail->next = newnode;
}
tail=newnode;
}


args * dequeue(){
if(head==NULL){
return NULL;
}else{
args *result = head->ar;
node_t *temp = head;
head=head->next;
if (head==NULL){tail==NULL;};
free(temp);
return result;
}
}



*/











/*
//Ñ„ÑƒÐ½ÐºÑ†Ð¸Ñ� Ð²Ð¾Ð¾Ð±ÑˆÐµ Ð´Ð»Ñ� Ñ‚Ð¸Ð¿Ð¾Ð² Ð´Ñ‹Ð½Ð½Ñ‹Ñ… Ð¸ Ð°Ñ€Ð³ÑƒÐ¼ÐµÐ½Ñ‚ Ð² Ñ‡Ð°Ñ�Ñ‚Ð½Ð¾Ñ�Ñ‚Ð¸
void *doSomeThing(void *arg)
{
//ar.y="test";
args* q=(args*)arg;

//sprintf(q->y,"%s","test");
//q->y="test";
// struct sockaddr_in addr;
 int socke = socket(AF_INET, SOCK_STREAM, 0);
 addr.sin_family = AF_INET;
 addr.sin_port = htons(PORT);
// pthread_create(&(tid[0]), NULL, &doSomeThing, NULL);
 //for(int i=202;i<204;i++){
 char a[256] = "192.168.1.";
 char b[10];
 //int c = i;
 sprintf(b,"%d",q->x);
 //a="192.168.1."
 strcat(a,b);
 //puts(a);
 addr.sin_addr.s_addr =  inet_addr(a);
 
 if(connect(socke, (struct sockaddr*)&addr, sizeof(addr))==0){sprintf(q->y,"%s",a);q->isServer=_Client;return 0;}
    return NULL;
}


void spawnThreads()
{


args ar[256]={NULL,0,"127.0.0.1",server};
///ar[0].isServer=server;
//args ar;
//printf("waiting for connection...");

int j=0;

for (int i=0;i<255;i++){
ar[j].x=i;
  pthread_create(&(tid[j]), NULL, &doSomeThing, &ar[j]);
  ar->tid=tid[j];
  enqueue(&ar[j]); 
j++;
}

}
*/



void connector( args *argz) {
args* q=(args*)argz;

 int socke = socket(AF_INET, SOCK_STREAM, 0);
 
addr.sin_family = AF_INET;
 addr.sin_port = htons(PORT);
 char a[256] = "192.168.1.";
 char b[10];
 sprintf(b,"%d",q->x);
 strcat(a,b);
 addr.sin_addr.s_addr =  inet_addr(a);
 
 if(connect(socke, (struct sockaddr*)&addr, sizeof(addr))==0){sprintf(q->y,"%s",a);q->isServer=_Client;}

}


//args ar[256]={};



export void spawnThreads()
{

    for (int i = 0; i < 1; i++) {
        ar[i].x=i;
        ar[i].tid = std::thread(connector,&ar[i]);
        qq.push(&ar[i]); 
   }


}

//enum  PeerType isserver=_Server;
//args *pclient;



export void wait()
{
while(!qq.empty()){
pclient=qq.front();
if((pclient!=NULL)&&(pclient->tid.joinable())){
pclient->tid.join();}
if(pclient)if(pclient->isServer==_Client){isserver=_Client;break;}
qq.pop();
}
}


/*
void check(){

enum PeerType isserver=server;
args *pclient;
pclient=dequeue();
while(pclient){
pclient=dequeue();
if((pclient!=NULL)&&(pclient->tid!=NULL)){
//if(tid[s]!=NULL)
pthread_join(pclient->tid,NULL);}
if(pclient)if(pclient->isServer==client){isserver=client;break;}
}

}
*/











export void check(){

if(isserver==_Client){
char a[256] = "192.168.1.";
 char b[10];
 sprintf(b,"%d",pclient->x);
  strcat(a,b);

}

out << "nick: " << std::endl;;
in >> s;

//fun(peer)->funct();
//ofstream out("/dev/stdout");
//ifstream in("/dev/stdin");

out << "0.server"<<std::endl;
out << "1.client"<<std::endl;
int p;
in >> p;
//peer = new Server;

//run((Server *)peer);
/*
switch(p){
	case 0: //{run((Server*)peer);break;}
	case 1: //{run(peer);break;}
}
*/


//run(.runn());
}
