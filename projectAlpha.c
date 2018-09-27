#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct account {
    char accountNum[10];
    double accountValue;
};
typedef struct account account_t;

struct user {
    char username[15];
    char password[15];
    char userID[6];   /*made 6 for \0*/
    account_t account[6];
    int numAccounts;  /*added, useful when writing to file*/
};
typedef struct user user_t;

struct node {
    struct node* nextp;
    user_t user;
};
typedef struct node *node_t; /* PS: made the first value a pointer*/




/*Prototypes*****************************/
node_t readFile();
int writeFile(node_t linkList, int numUsers);
node_t newUser(node_t linkList, int *numUsers);
void accountMenu(node_t linkList);

void addNewAccount(node_t linklist, char userID[]); /*Added userID*/
void PayUser(node_t linkList, int amount);
void TransferMoney(char accountNum1[],char accountNum2[],int amount);
void WithdrawMoney(char accountNum[],int amount);
void DepositMoney(char accountNum[],int amount);
void deleteAccount(char accountNum[]);
/***************************************************/

int main(void)
{
    return 0;
}


node_t newUser(node_t linkList, int *numUsers)
{
    ++*numUsers;
    node_t newUse, p; /*PS: now these are both pointers
                       *defines 2 new nodes*/
    
    newUse=(node_t)malloc(sizeof(node_t));
    p=(node_t)malloc(sizeof(node_t));
                      /*dynamically sets their size*/
    newUse->nextp=NULL;
                      /*sets the next node so that NULL will be the next link*/
    p=linkList;
                      /*p used to traverse the linklist*/
    while(p->nextp!=NULL)
    {
        p= p->nextp;
    }                 /*will stop when p=the last node before NULL*/
    
    p->nextp=newUse; /*changes the last node (previous NULL) to another node
                      * which points to NULL*/
    
   
    
    sprintf(p->nextp->user.userID,"05%d", *numUsers);eleteAccount(char
                            /*will set the User ID to the number of users in
                             * the system (including itself) with the leasing
                             * digits being zeros*/
                            
    printf("Enter Your Username> \n");
    scanf("%s", p->nextp->user.username);
    printf("Enter Your Password> \n");
    scanf("%s", p->nextp->user.password);
    printf("Welcome to Richard and Co Bank!!\n");
    
    addNewAccount(linkList, p->nextp->user.userID);
    
    free(p);
    p=NULL; /*frees the storage space*/
    
   return linkList;
    
}

int writeFile(node_t linkList, int numUsers)
{
    FILE*fp;
    
    fp=fopen("Database.txt", "w");
    
    if(fp==NULL) /*if file fails to open function ends*/
    {
        return 0;
    }
    
    if(numUsers==0) /*if there is no data to write function ends*/
    {
        return 0;
    }

    fprintf(fp, "%d ", numUsers); /*prints number of uses, used when reading
                                   * the file*/
    
    node_t p;
    p=(node_t)malloc(sizeof(node_t));
                                 /*sets data size for pointer*/
    int count;                   /*used to count through user accounts*/
    
    for(p=linkList; p!=NULL; p=p->nextp)
          /*prints each value for each user until the next */
    {
        fprintf(fp, "%s %s %s %d ", p->user.userID, p->user.username,
                                 p->user.userID, p->user.numAccounts);
          /*numAccounts used to determine how many accounts to print*/
          
        for(count=0; count<p->user.numAccounts; ++count)
        {
            fprintf(fp, "%s %lf ", p->user.account[count].accountNum,
                                   p->user.account[count].accountValue);
            /*prints account num and value for each account he user has*/
        }
    }
    
    fclose(fp);
    
    free(p);
    p=NULL; /*frees the storage space*/
    
    return 1; /*writing to file was successful*/
}

void accountMenu()
{
        char input;

/* printf("*********************************************************\n"
        "                              $$\n"
        "                          $$$$$$$$$\n"
        "                       $$$$$$$$$$$$$$\n"
        "                      $$$$$$$$$$$$$$$$$\n"
        "                      $$$$$   $$    $$$$$\n"
        "                      $$$$    $$     $$$$$$\n"
        "                      $$$$    $$      $$$$$$\n"
        "                        $$$$\n"
        "                          $$$$$\n"
        "                               $$$$\n"
        "                              $$ $$$$$$$\n"
        "                              $$     $$$$$$\n"
        "                              $$     $$$$$\n"
        "                              $$      $$$$\n"
        "                              $$     $$$$\n"
        "                              $$   $$$$$\n"
        "                       $$$$$$$$$$$$$$$$$$\n"
        "                        $$$$$$$$$$$$$$\n"
        "                              $$\n");
*/
                printf("1. Add Account\n"
                       "2. Delete Account\n"
                       "3. Transfer Between Accounts\n"
                       "4. Pay Others\n"
                       "5. Withdraw Money\n"
                       "6. Deposit Money\n"
                       "0. exit\n");
                        
                printf("Option: ");
                scanf("%c", &input);
                switch(input)
                {
                        case('1') : addNewAccount(linklist, userID);
                        case('2') : deleteAccount(accountNum[]);
                        case('3') : TransferMoney(char accountNum1[],char accountNum2[],int amount);
                        case('4') : PayUser(node_t linkList, int amount);
                        case('5') : WithdrawMoney(char accountNum[],int amount);
                        case('6') : DepositMoney(char accountNum[],int amount);
                        case('0') : exit(0);
                        default : printf("Please enter an option 1-6 or quit with 0\n");
                }
}

void PayUser(node_t linkList, myuserid)
{
  char id[15];
  double amount;
  char accountNum1[10];
   char accountNum2[10];

  printf("What is the userid of the user you want to pay ?\n" );
  scanf("%s", &id);

  printf("How much do you want to pay ?\n");
  scanf("%lf", &amount);

  printf("What is the account number you want to pay ?\n");
  scanf("%s", &accountNum2);

  printf("With wich account do you want to pay?\n");
  scanf("%s", &accountNum1);
  
    node_t i;
        for(i = user; i != NULL; i = i->nextp)
        {
            if(strcmp(user.userid, id) == 0)
            {
                 int j;
                 for(j = 0; j < 6; j++)
                 {
                        if(strcmp(account[j].accountNum2, accountname) == 0)
                        {
                            account[j].accountNum2 += amount;
                            myuserid.accountNum1 -= amount;
                            printf("Mr/Miss %s has been paid \n",id );
                        }
                        else
                        {
                            printf("No account found with that account number \n" );
                        }
                else
                {
                    printf("No user find with that id \n" );
                }
            }
        }
    }

}
