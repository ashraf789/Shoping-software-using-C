#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>


/*
	@author : syed ashraf ullah
	@Contributor : Moshiur, Dipta, Rabbani, Shamrat
	data: 8.10.15
	email: syedashrafullah15@gmail.com
	subject: course project (Project 1 with C)
*/


///------------Fuction Declear------------
void login();
void showproduct();
void Productamount();
void Addproduct();
void Padmin();
void Pdelete();
void User();
void ChoiceProduct();
void DeleteChoiseProduct();
void GiveRecipt();
int CalculatePay();
void Passcheck();
void AdminCommand();
void ShowSaleDetale();//Function declear End


///------------Global Variable Declear----
int Pamount,i=0,j=0;//Global Variable Declear End


///-------------Product structure---------
struct Newproduct
{
    char Ptype[30];
    int Pcode;
    char Pbname[50];
    char Pmodel[20];
    int price;

}newproduct[5];///Newproduct variable declear
//product structure end

///-------------Show Sale Detale----------
struct User//Take Sale Detale
{
    char name[50];
    char phone[12];
    int Tprice;
}ShowUser[3]; ///Show Customar Sale Detale Variable Declear
//End User Structure


///--------------Main Fuction----------------

int main(){

    puts("\n\n\t***************** wellcome Sir In Our Shop ********************\n");
    Productamount();//calculate total product amount
    login();//login check

    return 0;
}//main function end



///---------------------All Function ------------------------------


///----------Log in------------
login(){
    char t;
    puts("\n\n");

    puts("\tFor User Log in Press '1'");
    puts("\tFor Just Enter Shop Press '2'");
    puts("\n");
    t = getch();
    printf("*");

    switch (t){
        case '1':
            Passcheck();
            break;
        case '2':
            User();//For User
            break;
        default:
            printf("\n\aInvalide Key Please Enter Valide Keyward\n");
            login();
    }
}//Log In fuction End


///----------Pasward Check For Log In------------
Passcheck(){
    printf("\n\n");
    char name[50];
    char pass[10],a;
    int i=0;
    int n,p;

    printf("Enter Your User Name (case sensitive)\n");
    scanf("%s",name);
    printf("Enter Your Password (case sensitive)\n");
    while(1){
        a = getch();
        if(a ==13){
            break;
        }
        printf("*");
        pass[i] = a;
        i++;
    }
    pass[i]='\0';

    n = strcmp("admin",name);
    p = strcmp("123456",pass);
    if(n == 0 && p == 0){
        Padmin();//for admin panel
    }else{
        printf("\n\a\tWrong Password Or User Name Please Enter Valide Password And User Name\n");
        Passcheck();
    }
}//End Password Check Function


///-------------For Padmin--------
Padmin(){

    printf("\n\n\n\n\n");
    printf("\t\t\t\tAdmin Panel\n\n\n\n");
    showproduct();
    AdminCommand();

    printf("\t************************** Thank You Admin ****************************\n");

    /*
    ------------------------Product Sample---------------------
    Laptop           1001          Hp        Probook-S    51000
    Laptop           1002          Acer      Ashpire      45000
    Laptop           1003          Dell      Chromebook   35000
    Mobile           1004          Nokia     X-cel        12300
    Mobile           1005          Nokia     Lumia        48750
    Mobile           1006          Htc       Desiar-826   68000
    Mobile           1007          Samsung   S6           66150
    Pendrive         1008          Sandisc   iXpand-16GB   4600
    Pendrive         1009          Trancend  p5             620
    Tablet           1010          Samsung   Note-2       78850
    */
}//Padmin Function End


///------------Admin Menu Selection--------
AdminCommand(){

    int c;//here c = command

    printf("\t\tIf You Want to add more product press     : 1\n");
    printf("\t\tIf You Want to Delete product press       : 2\n");
    printf("\t\tIf You Want to Show Sell Detale press     : 3\n");
    printf("\t\tIf You Want to Show Present Product press : 4\n");
    printf("\t\tIf You Want to Stop It Just press         : 0\n");


    while(1){

        scanf("%d",&c);

        if(c == 1){
            Addproduct();
            c = 0;
            AdminCommand();
        }
        else if(c == 2){
            Pdelete();
            c = 0;
            AdminCommand();
        }
        else if(c == 3){
            ShowSaleDetale();
            c = 0;
            AdminCommand();
        }
        else if(c == 4){
            showproduct();
            c = 0;
            AdminCommand();
        }

        if(c == 0)
            break;
        else{
            printf("\a\t\tEnvalide Keyward Please Enter Valide Key\n");
        }

        scanf("%c",&c);
    }

}//End Admin Menu Select Function


///----------Add New Product For admin panel-----
Addproduct(){
    FILE *fwrite;
    fwrite = fopen("product.txt","a");
    printf("Enter Product Type\t ProductCode\t Brand Name\t Model Name\t Price \nFor Break Press (ctrl+z)\n");
    while(scanf("%s%d%s%s%d",&newproduct[i].Ptype,&newproduct[i].Pcode,&newproduct[i].Pbname,&newproduct[i].Pmodel,&newproduct[i].price) !=EOF){
        fprintf(fwrite,"%10s%15d%15s%20s%15d\n",newproduct[i].Ptype,newproduct[i].Pcode,newproduct[i].Pbname,newproduct[i].Pmodel,newproduct[i].price);
        i++;
    }

    printf("\n\n\n");
    fclose(fwrite);

}//add product function end


///------------Product Delete Function For Admin Panel-------------
Pdelete(){
    i = 0;
    j = 0;
    struct Newproduct Reproduct[Pamount];
    FILE *fread;
    fread = fopen("product.txt","r");//End Reader

    FILE *fwrite;
    fwrite = fopen("product.txt","w");//End Writer


    int c,got=0;//C = Product code
    printf("\tEnter Deletable Product Code Or stop it just press '0'\n");
    while(1){
        scanf("%d",&c);
        for(i = 0; i < Pamount; i++){
            fscanf(fread,"%s%d%s%s%d",&newproduct[i].Ptype,&newproduct[i].Pcode,&newproduct[i].Pbname,&newproduct[i].Pmodel,&newproduct[i].price);
            if(newproduct[i].Pcode == c){
                got = 1;
                continue;
            }

            strcpy(Reproduct[j].Ptype,newproduct[i].Ptype);
            Reproduct[j].Pcode = newproduct[i].Pcode;
            strcpy(Reproduct[j].Pbname,newproduct[i].Pbname);
            strcpy(Reproduct[j].Pmodel,newproduct[i].Pmodel);
            Reproduct[j].price = newproduct[i].price;

            fprintf(fwrite,"%10s%15d%15s%20s%15d\n",Reproduct[j].Ptype,Reproduct[j].Pcode,Reproduct[j].Pbname,Reproduct[j].Pmodel,Reproduct[j].price);
            j++;
        }

        if(c == 0){
            break;
        }

        if(got == 1){
            printf("No %d  code product Deleted %d\n",c,i);
        }else{
            printf("not Found\n");
        }
        got = 0;
        i=0;
        j=0;
    }

    fclose(fread);
    fclose(fwrite);
}//Pdelete Function End


///------------Show Product Sale Detale-----
ShowSaleDetale(){

    int i=0;
    FILE *SDreader;//sale detale reader
    SDreader = fopen("productSale.txt","r");
    printf("\n\n\tCustomar Name\t Phone Number\t Total ShopingAmount\n\n");
    while(fscanf(SDreader,"%s%s%d",ShowUser[i].name,ShowUser[i].phone,&ShowUser[i].Tprice) !=EOF){

        printf("%15s%22s%15d\n",ShowUser[i].name,ShowUser[i].phone,ShowUser[i].Tprice);
        i++;
    }
    printf("\n\n");

    fclose(SDreader);

}


///--------------Show Total Product------
showproduct(){

    FILE *fread;
    fread = fopen("product.txt","r");//End Reader

    int j=0;
    puts("************************** Present Shop Products *******************************\n");

    printf("Product Type\t ProductCode\t Brand Name\t Model Name\t Price\n\n");
    while(fscanf(fread,"%s%d%s%s%d",&newproduct[j].Ptype,&newproduct[j].Pcode,&newproduct[j].Pbname,&newproduct[j].Pmodel,&newproduct[j].price) != EOF){
        printf("%10s%15d%15s%20s%15d\n",newproduct[j].Ptype,newproduct[j].Pcode,newproduct[j].Pbname,newproduct[j].Pmodel,newproduct[j].price);
        j++;
    }
    puts("\n\n");
    fclose(fread);
}//show product function end


///--------------Product amount------
Productamount(){

    FILE *fread;
    fread = fopen("product.txt","r");//End Reader

    int j = 0;
    while(fscanf(fread,"%s%d%s%s%d",newproduct[j].Ptype,&newproduct[j].Pcode,newproduct[j].Pbname,newproduct[j].Pmodel,&newproduct[j].price) != EOF){
        j++;
    }
    Pamount = j;


    puts("\n\n");
    fclose(fread);

}//calculate prduct amount function end


///------------For User-------------
User(){
    showproduct();
    ChoiceProduct();

}//User function end


///------------Choice Product Function-------------
ChoiceProduct(){

    int j =0;
    FILE *fread;
    fread = fopen("product.txt","r");//End Reader

    int Pchoice[50];//Product Choise
    int Fpcode;//File Product Code
    int Pcode;//product Code
    int Got=0;//Check Valide Pcode
    int CPamount=0;//Choise Product amount
    int Tprice=0;//Total Price

    ///Add Product Into Buy List
    printf("\tEnter Product Code That Your Choice Or Press (-1) For Buy\n");
    while(scanf("%d",&Pcode)){
        if(Pcode == -1)
            break;
        //For Checking Product Code Validation
        for(i = 0; i < Pamount; i++){

            fscanf(fread,"%s%d%s%s%d",&newproduct[i].Ptype,&newproduct[i].Pcode,&newproduct[i].Pbname,&newproduct[i].Pmodel,&newproduct[i].price);
            if(Pcode == newproduct[i].Pcode){
                Got =1;
            }
        }
        // Adding Product Into Choice List
        if(Got == 1){
            Pchoice[j] = Pcode;
            printf("%d Product Code Added Your List\n",Pcode);
            j++;
            Got = 0;
        }else
            printf("%d Product Code Invalide Enter Valide Product Code\n",Pcode);
    }//End Buy List Adding



    ///Show Choiced Product List
    printf("\n\nYour Choiced Product Code\t Product Name\t\t Model\t\t Price\n");
    int p = 0;
    while(j > p){

        //Print Product Detale From Product Code
        for(i = 0; i < Pamount; i++){

            fscanf(fread,"%s%d%s%s%d",&newproduct[i].Ptype,&newproduct[i].Pcode,&newproduct[i].Pbname,&newproduct[i].Pmodel,&newproduct[i].price);
            if(Pchoice[p] == newproduct[i].Pcode){
                printf("%25d%20s%17s%15d\n",newproduct[i].Pcode,newproduct[i].Pbname,newproduct[i].Pmodel,newproduct[i].price);
                Tprice = Tprice + newproduct[i].price;//Calculate Toatl Payble Money
                CPamount++;
                break;
            }
        }
        p++;

    }//End Showing Product List

    printf("\n\n\n\t\tYou Want To Buy %d Product You Need : %d Take\n\n",CPamount,Tprice);



    ///For Product Delete
    printf("\n\n\nIf You Want To Delete Any Product From Your List Press (1) Else Press (0)\n");
    int t=0,k=0;
    scanf("%d",&t);

    if(t == 1){
        printf("\nEnter Product Code That You Want To delete Press (0) For Stop Deleting\n");
        while(scanf("%d",&Pcode)){
            if(Pcode == 0)
                break;
            for(i = 0; i < Pamount; i++){

                if(Pcode == Pchoice[i]){
                    Got =1;
                    continue;
                }
                Pchoice[k] = Pchoice[i];
                k++;
            }
            if(Got == 1){
                printf("%d Product Code Deleted From Your List\n",Pcode);
                Got = 0;
                CPamount--;
            }else
                printf("%d Product Code Invalide Enter Valide Product Code\n",Pcode);
        }//End Deleting



        ///Show Present Product List
        j = 0;
        Tprice = 0;

        printf("\n\n\nYour Choiced Product Code\t Product Name\t\t Model\t\t Price\n");
        while(CPamount > j){

            //Print Present Product Detale From Choce List
            for(i = 0; i < Pamount; i++){

                fscanf(fread,"%s%d%s%s%d",&newproduct[i].Ptype,&newproduct[i].Pcode,&newproduct[i].Pbname,&newproduct[i].Pmodel,&newproduct[i].price);
                if(Pchoice[j] == newproduct[i].Pcode){
                    printf("%25d%20s%17s%15d\n",newproduct[i].Pcode,newproduct[i].Pbname,newproduct[i].Pmodel,newproduct[i].price);
                    Tprice = Tprice + newproduct[i].price;//Calculate Toatl Payble Money
                    break;
                }
            }
            j++;
        }//End Showing Product List
        printf("\n\n\nYou Want To Buy %d Product You Need : %d Take\n\n",CPamount,Tprice);

    }//End Product Deleting

    ///Calculate Pay
    int Bmoney; //Money Will Be Back
    Bmoney = CalculatePay(Tprice);

    ///Make Recipt
    GiveRecipt(CPamount,Tprice,Bmoney);

    fclose(fread);
}//End Choise Product Function


///-------------Calculate Payable-----------------
CalculatePay(int Tprice){

    int take,payed,yes=0;

    printf("\n\n\t\tPay Your Money  For Buy Your Listed Product\n");
    scanf("%d",&take);

    payed = take - Tprice;

    if(payed < 0){

        while(payed < 0){
            printf("\t You Need To Pay %d Take Please Pay First Else You Can Not Buy It\n",(payed*-1));
            scanf("%d",&take);
            payed = take - (payed*-1);

        }
    }
    if(payed >= 0)
        return payed;

}//End calculation


///----------------Give Recipt------------------
GiveRecipt(int CPamount,int Tprice,int Bmoney){

    char Name[50];
    char PhoneNo[12];

    printf("\n\n\t\t Enter Your Name And phone Number\n");
    scanf("%s%s",&Name,&PhoneNo);

    printf("\n\n\n\n\n");
    printf("\t\t***********************Recipt********************\n\n");
    printf("\t\t Customar Name         :              %s\n",Name);
    printf("\t\t Customar Phone No     :              %s\n",PhoneNo);
    printf("\t\t Product Amount        :              %d Piss\n",CPamount);
    printf("\t\t Total Cost            :              %d Take\n",Tprice);
    printf("\t\t Customar Will Be Back :              %d Take\n\n",Bmoney);
    printf("\t\t**************************************************\n");
    printf("\t\t Clearence             :                Ok\n\n");

    printf("\n\n\n*************************** Thank You Sir For Shoping **************************\n\n\n");

    ///----Keep sale detale----
    FILE *sdetale;//Sale Detale
    sdetale = fopen("productSale.txt","a");

    fprintf(sdetale,"%s\t%s\t%d\n",Name,PhoneNo,Tprice);
    fclose(sdetale);


}//End Recipt Function
