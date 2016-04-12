 #include <stdlib.h>
 #include <strings.h>
 #include <stdio.h>
 #include <fcntl.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/stat.h>
 #include <netinet/in.h>
 #include <netdb.h> 
 #include <unistd.h>
 #include <signal.h>

#define MAX_BUF 1024

int sockfd;
int ii=1;
int jj=1;
void sig_handler(int);
void error(char *);
void waitFor(unsigned int);

 
 int main(int argc, char *argv[])
 {
    int fd;
    char * myfifo = "fifo";
    mkfifo(myfifo, 0666);
    char buf[MAX_BUF];
     int portno, n;
 
     struct sockaddr_in serv_addr;
     struct hostent *server;
 
     char buffer[256];
     if (argc < 3)
     {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
     }

     portno = atoi(argv[2]);
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
         error("ERROR opening socket");
     server = gethostbyname(argv[1]);

     if (server == NULL) 
     {
         fprintf(stderr,"ERROR, no such host\n");
         exit(0);
     }

     bzero((char *) &serv_addr, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
     serv_addr.sin_port = htons(portno);
     if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
         error("ERROR connecting");


    char* arg_list[] = 
    {
    	"display",
    	"0.jpg",
    	NULL
    };

     int init = 0;
     
     pid_t child_pid;
     child_pid = fork ();
     int a = (int) getpid ();
    if (child_pid == 0)
    { 
     	int b = (int) getpid ();
     	execvp("display", arg_list); 
    }
    else
    {
         int c = (int) getpid ();
         child_pid = fork ();
        if(child_pid==0)
        {
         	int d = (int) getpid ();
            	int i =0;
                do
                { 
                    bzero(buffer,256);
                    n = read(sockfd,buffer,255);
                    fd = open(myfifo, O_WRONLY);
                    
                    switch(buffer[0])
                    {
                        case '0':
                        	if(i>1)
                        	{
                            	write(fd, "0", sizeof("0"));
                        	}
                        	else
                        	{
                        		i++;
                        	}
                        break;
                        case '1':
                        	if(i>1)
                        	{
                            	write(fd, "1", sizeof("1"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '2':
                        	if(i>1)
                        	{
                            	write(fd, "2", sizeof("2"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '3':
                        	if(i>1)
                        	{
                            	write(fd, "3", sizeof("3"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '4':
                        	if(i>1)
                        	{
                            	write(fd, "4", sizeof("4"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '5':
                        	if(i>1)
                        	{
                            	write(fd, "5", sizeof("5"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '6':
                        	if(i>1)
                        	{
                            	write(fd, "6", sizeof("6"));
                            }
                            else
                            {
                            	i++;
                            }
                        break;
                        case '7':
                        	if(i>1){
                            	write(fd, "7", sizeof("7"));
                            }else{i++;}
                        break;
                        case '8':
                        	if(i>1){
                            	write(fd, "8", sizeof("8"));
                            }else{i++;}
                        break;
                        case '9':
                        	if(i>1){
                            write(fd, "9", sizeof("9"));
                            }else{i++;}
                        break;
                    }
                    close(fd);
                    if (signal(SIGINT, sig_handler) == SIG_ERR)
                    {
	  					printf("\nCan't catch signal\n");
                    }
                }while (ii==1);   
        }
        else{
           	int e = (int) getpid ();
           	int j=0;
           	do
           	{ 
                fd = open(myfifo, O_RDONLY);
                read(fd, buf, MAX_BUF);
                char a = buf[0];
                switch(a)
                {
                    case '0':
                      	if(j>1)
                       	{
                           	system("display -remote 0.jpg");
      	                }
                        else
                        {
                          	j++;
                        }
                            break;
                    case '1':
                       	if(j>1)
                       	{
                           	system("display -remote 1.jpg");
                        }
                        else
                        {
                           	j++;
                        }
                            break;
                        case '2':
                        	if(j>1)
                        	{
	                            system("display -remote 2.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '3':
                        	if(j>1)
                        	{
                            	system("display -remote 3.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '4':
                        	if(j>1)
                        	{
                            	system("display -remote 4.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '5':
                        	if(j>1)
                        	{
                            	system("display -remote 5.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '6':
                        	if(j>1)
                        	{
                            	system("display -remote 6.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '7':
                        	if(j>1)
                        	{
                            	system("display -remote 7.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '8':
                        	if(j>1)
                        	{
	                            system("display -remote 8.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                        case '9':
                        	if(j>1)
                        	{
                            	system("display -remote 9.jpg");
                            }
                            else
                            {
                            	j++;
                            }
                            break;
                    }
                    close(fd);
                    if (signal(SIGINT, sig_handler) == SIG_ERR)
                    {
	  					printf("\nLa señal no puede ser cachada\n");
                    }
                }while (jj==1);
            }
        }
 }

void sig_handler(int signo)
{
  if (signo == SIGINT)
  {
    printf("Recibio un comando SIGINT\n");
    close(sockfd);
    exit(1);
    ii++;jj++;
  }
}

void error(char *msg)
{
     perror(msg);
     exit(0);
}