#include<stdio.h>
#include<string.h>
void invoice();
void searchmedicine();
void viewmedicine();
void addmedicinefile();
void admin();
void staff();
void login();
void page1();

struct medicine{
    char name[100];
    char manufacturer[100];
    int serial_no;
    float price;
    char expiry_date[50];
};

int main(){
    printf("\n");
    printf("\t\t\t\t\t\033[1;33m IJ Pharmacy Management system\033[m\n");
    printf("\n");
    
    page1();

    return 0;
}
void page1(){
    printf("\033[0;34m Welcome to the Login Page\033[m\n");
    printf("==========================\n");
    printf("1. Admin\n");
    printf("2. Staff\n");
    printf("Enter your choice (1 or 2): ");
    
    int n;
    scanf("%d",&n);
    switch(n){
        case 1:
        login();
        break;
        case 2:
        login();
        break;
        default:
        printf("\033[1;31mInvalid Option!!\033[1;32mPlease Enter a Valid Number\033[m\n");
        page1();
        
    }
}
void login() {
    getchar();
    char name[100], pass[100];
    printf("Enter your username: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter your password: ");
    fgets(pass, sizeof(pass), stdin);
    pass[strcspn(pass, "\n")] = '\0'; 
     char adminname[]={"admin"};
     char adminpass[]={"admin123"};
     char staffname[]={"staff01"};
     char staffpass[]={"staff123"};

    if(strcmp(name,adminname)==0 && (strcmp(pass,adminpass)==0))
        {admin();}
    else if(strcmp(name,staffname)==0 && (strcmp(pass,staffpass)==0))
        {staff();}
    else {
        printf("\033[1;31mAuthentication Error!Please try again\033[m");
        login();}
   }

void admin(){
    
    int a_choice;
    printf("\n\033[1;32mLogin successful.Welcome Admin\033[m\n");
    printf("======Admin menu======\n");
    printf("1.View Medicines\n");
    printf("2.Add Medicines\n");
    printf("3.Search Medicine\n");
    printf("4.Return\n");
    printf("5.Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d",&a_choice);

    switch(a_choice)
    {   
        case 1:
        viewmedicine(); break;
        case 2:
        addmedicinefile(); break;
        case 3:
        searchmedicine(); break;
        case 4:
        page1(); break;
        case 5:
        printf("Exited Successfully");
        return; break;
        
        default:
        printf("\033[1;31mInvalid Choice.Please Enter a Valid Number\033[m");
        admin();
        break;

    }
}
void staff(){
    
    int s_choice;
    printf("\n\033[1;32mLog in Successful\nWelcome\033[m\n");
    printf("======Staff Menu======\n");
    printf("1.View Medicines\n");
    printf("2.Search Medicine\n");
    printf("3.Customer invoice\n");
    printf("4.Return\n");
    printf("5.Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d",&s_choice);

    switch(s_choice)
    {   
        case 1:
        viewmedicine(); break;
        case 2: 
        searchmedicine(); break;
        case 3:
        invoice(); break;
        case 4:
        page1(); break;
        case 5:
        printf("Exited Successfully");
        return; break;
       
        default:
        printf("Invalid Choice.Please Enter a Valid Number");
        staff();
        break;

    }
}

void addmedicinefile(){
    printf("\033[1;32mEnter required details to add medicine.\033[m\n");
    struct medicine m;
    printf("Enter medicine name: ");
    getchar();
    fgets(m.name,sizeof(m.name),stdin);
    m.name[strcspn(m.name,"\n")]='\0';

    printf("Enter medicine manufacturer name: ");
    fgets(m.manufacturer,sizeof(m.manufacturer),stdin);
    m.manufacturer[strcspn(m.manufacturer,"\n")]='\0';

    printf("Enter medicine serial number:");
    scanf("%d",&m.serial_no);

    printf("Enter medicine price: ");
    scanf("%f",&m.price);
    getchar();

    printf("Enter medicine expiry date: ");
    fgets(m.expiry_date,sizeof(m.expiry_date),stdin);
    m.expiry_date[strcspn(m.expiry_date,"\n")]='\0';

    FILE *f=fopen("medicine.txt","a");
    if(f==NULL){
        printf("Error opening file.\n");  return ;
    }

    fprintf(f,"Name: %s\n",m.name);
    fprintf(f,"Manufacturer: %s\n",m.manufacturer);
    fprintf(f,"Serial No: %d\n",m.serial_no);
    fprintf(f,"Price: %.2f\n",m.price);
    fprintf(f,"Expiry Date: %s\n",m.expiry_date);
    fclose(f);
    printf("\033[1;36mMedicine Added Successfully.\033[m\n");
    int again;
    printf("To add another medicine  press 1 ; else press any number key.");
    scanf("%d",&again);
    if(again==1 ) addmedicinefile();
    else { printf("\033[1;32mExited successfully\033[m");
        return;}

}

void viewmedicine() {
    FILE *f = fopen("medicine.txt", "r");

    if (f == NULL) {
        printf("\033[0;31mNo records found.\033[m\n");
        return;
    }

    struct medicine m;

    printf("\n--- Medicine List ---\n");

    while (fscanf(f, "Name: %[^\n]\n", m.name) == 1 &&
    fscanf(f, "Manufacturer: %[^\n]\n", m.manufacturer) == 1 &&
    fscanf(f, "Serial No: %d\n", &m.serial_no) == 1 &&
    fscanf(f, "Price: %f\n", &m.price) == 1 &&
    fscanf(f, "Expiry Date: %[^\n]\n", m.expiry_date) == 1) {

        printf("Name: %s | Manufacturer: %s | ID: %d | Price: %.2f | Expiry: %s\n",
               m.name, m.manufacturer, m.serial_no, m.price, m.expiry_date);
    }
    fclose(f);
}

void searchmedicine() {
    FILE *f=fopen("medicine.txt","r");
    if (f == NULL){
        printf("\033[0;31mNo records found.\033[m\n");
        return;
    }

    char search_name[100];
    struct medicine m;
    int found = 0;
    getchar();
    printf("Enter the medicine name to search: ");
    fgets(search_name,sizeof(search_name),stdin);
    search_name[strcspn(search_name, "\n")] = '\0';

    while (fscanf(f, "Name: %[^\n]\nManufacturer: %[^\n]\nSerial No: %d\nPrice: %f\nExpiry Date: %[^\n]\n",
        m.name, m.manufacturer, &m.serial_no, &m.price, m.expiry_date) == 5) {
        if (strcasecmp(m.name, search_name) == 0) {
            printf("\nMedicine Found!\n");
            printf("Name: %s | Manufacturer: %s | ID: %d | Price: %.2f | Expiry: %s\n",
                m.name,m.manufacturer,m.serial_no,m.price,m.expiry_date);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\033[0;31mMedicine '%s' not found.\n\033[m",search_name);
    }

    fclose(f);
} 
void invoice() {
    FILE *f=fopen("medicine.txt","r");
    if (f==NULL) {
        printf("\033[0;31mNo medicines available.\033[m\n");
        return;
    }

    struct medicine m;
    char medicine_name[100];
    char customer_name[100];
    int quantity,found=0;
    float total = 0.0;
   

    printf("\n\033[1;33m--- Invoice Generation ---\033[m\n");

    printf("Enter medicine name: ");
    getchar(); 
    fgets(medicine_name,sizeof(medicine_name),stdin);
    medicine_name[strcspn(medicine_name, "\n")] = '\0'; 

    while (fscanf(f,"Name: %[^\n]\nManufacturer: %[^\n]\nSerial No: %d\nPrice: %f\nExpiry Date: %[^\n]\n",
        m.name, m.manufacturer, &m.serial_no, &m.price, m.expiry_date) == 5) {
        
        if (strcasecmp(m.name,medicine_name) == 0) {
            found = 1;
            printf("Medicine found: %s | Price: %.2f\n",m.name,m.price);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            getchar();
            printf("Enter Customer Name: ");
            fgets(customer_name,100,stdin);
            customer_name[strcspn(customer_name,"\n")]='\0';
            total = m.price*quantity;

            printf("\n\033[1;35m--- Invoice ---\033[m\n");
            printf("\033[0;34mMedicine: %s\n",m.name);
            printf("Manufacturer: %s\n",m.manufacturer);
            printf("Quantity: %d\n",quantity);
            printf("Unit Price: %.2f\n", m.price);
            printf("Total: %.2f\n", total);
            printf("Customer:%s\033[m\n",customer_name);

            break; 
        }
    }
    int a;
    if (found==0) {
        printf("\033[0;31mNo medicine found with the name '%s'.\033[m\n", medicine_name);
        printf("Do You Want to Add Another Medicine? YES(1) or NO(0)");
        scanf("%d",&a);
        if(a==1)invoice();
        if(a==0){ printf("\033[1;33mExited successfully\033[m"); return;}
     }
    fclose(f);
}
    
   