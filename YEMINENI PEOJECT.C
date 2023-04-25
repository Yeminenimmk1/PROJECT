#include<stdio.h>
#include<stdlib.h>

struct movie{
	int T;
	double ph;
	char name[100];
	char gmail[60];
	
	
}M;
//struct movie M;
char M_ID[500];
int tickets(){
	M_ID[500]=("Your Booking ID %d",(M.T*M.ph)/1000);
	FILE *fp;
	fp =fopen("D:\\Mine Code\\C Files\\Tickets.txt","a");
	printf("\nYour Ticket Id is %d\n",(M.T*M.ph)/1000);
	fprintf(fp,"Your Ticket Id is %d",(M.T*M.ph)/1000);
	fclose(fp);
}
void show_time(){
	int i;
	char t[4][20]={"11:00AM","2:30PM","6:30PM","9:30PM"};
	printf("Select Show Timings:\n");
	printf("1.11:00AM\n2.2:30PM\n3.6:30PM\n4.9:30PM\n");
	scanf("%d",&i);
	printf("You selected %s\n",t[i-1]);
	FILE *fp;
	fp =fopen("D:\\Mine Code\\C Files\\Tickets.txt","a");
	fprintf(fp,"Show Time:%s\n",t[i-1]);
	fclose(fp);
	
}
int payment(){
	int p;
	int c;
	int cvv;
	int date;
	char upi[40];
	printf("Select The Payment Option: \n");
	printf("1.Debit/Credit Card\t2.Online Payment\n");
	scanf("%d",&p);
	if(p==1){
		printf("Please Enter The Cards Details: \n");
		printf("Enter The card Number: ");
		scanf("%d",&c);
		printf("Enter The CVV: ");
		scanf("%d",&cvv);
		printf("Enter the Month/Year: ");
		scanf("%d",&date);
		printf("Payment was Succesful ");
		tickets();
		}
		if(p==2){
			printf("Enter Your UPI ID: ");
			scanf("%s",upi);
			printf("UPI ID Verified:\n");
			
			printf("Payment was Succesful");
			tickets();
		}	
}
void booking(){
	printf("Registration:\n");
	printf("Enter Your Name: ");
   fflush(stdin); // clear the input buffer
	gets(M.name);
	printf("Enter Your Phone Number: ");
	scanf("%d",&M.ph);
	printf("Enter Your Gmail: ");
	scanf("%s",M.gmail);
	printf("\n");
	printf("\nEach Ticket Price is 150 Rupees\n");
	printf("How Many Tickets You Want: ");
	scanf("%d",&M.T);
	if(M.T>6){
		printf("You can only Book 6 Tickets: \n");
		printf("How many Tickets You want: ");
		scanf("%d",&M.T);
	}
	printf("You Selected %d Tickets\n",M.T);
	printf("Total Cost = %d\n",150*M.T);
	
	payment();
	
	
	
}
void hindi(){
	int l;
	char n[2][30]={"Pathan","War"};
	printf("Select The Movie:\n");
	printf("1.Pathan\t2.War\n");
	scanf("%d",&l);
	FILE *fp;
	fp=fopen("D:\\Mine Code\\C Files\\Tickets.txt","a");
	fprintf(fp,"Movie Name:%s\n",n[l-1]);
	fclose(fp);
	
		show_time();
		booking();
}
void telugu(){
	int k;
	char n[2][30] ={"Dasara","Agent"};
	printf("Select The Movie:\n");
	printf("1.Dasara\t2.Agent\n");
	scanf("%d",&k);
		FILE *fp;
		fp = fopen("D:\\Mine Code\\C Files\\Tickets.txt","a");
		fprintf(fp,"Movie Name:%s\n",n[k-1]);
		fclose(fp);
		show_time();
		booking();

	
}
void selecting(){
	int m;
	FILE *fp;
	fp=fopen("D:\\Mine Code\\C Files\\Tickets.txt","w");
	fclose(fp);
	printf("Select Language:\n");
	printf("1.Telugu\t2.Hindi\n");
	scanf("%d",&m);
	switch(m){
		case 1:
			telugu();
			break;
		case 2:
			hindi();
			break;
}
	
}
void view(){
char ch;
FILE*fp;
fp= fopen("D:\\Mine Code\\C Files\\Tickets.txt","r");
printf("Your Movie Details:\n");
while(!feof(fp)){
	ch=fgetc(fp);
	printf("%c",ch);
	
}printf("\n");
fclose(fp);
	
}
void cancel(){
	char ch;
	FILE *fp;
	fp =fopen("D:\\Mine Code\\C Files\\Tickets.txt","r");
	printf("Your Movie Details:\n");
	while(!feof(fp)){
		ch=fgetc(fp);
		printf("%c",ch);
}
fclose(fp);
fp=fopen("D:\\Mine Code\\C Files\\Tickets.txt","w");
fprintf(fp,"No Tickets Found\n");
printf("\nYour Tickets are cancelled\n");
printf("\n THANKS FOR VISITING\n");
printf("\n you can leave by pressing the option Exit(4)\n");
	
}

int main(){
	printf("WELCOME to MY MOVIE TICKET BOOKING WEBSITE\n");

	int n;
	
	do {	
	printf("_______________________________\n");
	printf("Select The Following Options:\n");
	printf("1.Book a Movie Ticket\t2.Cancel Ticket\n3.View Tickets\t\t4.Exit\n");
	printf("Enter Your Choice: ");
	scanf("%d",&n);
	switch(n){
		case 1:
			selecting();
			break;
		case 2:
			cancel();
			break;
		case 3:
			view();
			break;
		case 4:
			printf("Thank You!");
			break;
		
	}
	}
	while(n!=4);
	

	return 0;
}
