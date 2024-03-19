#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include <time.h>

#define MAX_STAFF_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_LINE_LENGTH 1000

char login_id[MAX_STAFF_LENGTH];
char login_password[MAX_PASSWORD_LENGTH];

char file_staff_id[MAX_STAFF_LENGTH];
char file_staff_password[MAX_PASSWORD_LENGTH];

void get_login_info() {
    printf("\nEnter your ID: ");
    scanf("%s", login_id);
    printf("Enter your password: ");
    scanf("%s", login_password);
}

bool check_role(char role[]) {
    char line[MAX_LINE_LENGTH];
    FILE *file = fopen(role, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return false;
    }

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        sscanf(line, "%s %s", file_staff_id, file_staff_password);
        if (strcmp(login_id, file_staff_id) == 0 && strcmp(login_password, file_staff_password) == 0) {
            fclose(file);
            return true;
        }
    }
    fclose(file);
    return false;
}

int auto_staff_id(){
    int max=10001;
    char line[10000];

    FILE * file_id = fopen("staff_id.txt", "r");
    if(file_id == NULL){
        printf("Not able to open existing file creating new file");
    }
    while (fgets(line, 10000, file_id) != NULL){
        sscanf(line, "%s %s", file_staff_id, file_staff_password);
        int x = atoi(file_staff_id);
        if (x>max)
            max=x;

        max++;
    }
    fclose(file_id);
    return max;
}

void add_staff_information(){
    bool x=true;
    int choice_dep,school_choice,max;

    char id[10];
    char password[10];
    char name[50];
    char gender[10];
    int int_phone_number;
    char email[50];
    char annual_leave[10];
    char compassionate_leave[10];
    char emergency_leave[10];
    char medical_leave[10];
    char maternity_leave[10];
    char school[1000];
    char department[1000];

    char check_id[10];
    char check_password[10];
    char file_name_id[1000];

    FILE * file_id = fopen("staff_id.txt", "a");
    if(file_id == NULL){
        printf("Not able to open existing file creating new file.");
        file_id = fopen("staff_id.txt", "w");
    }

    printf("\n--------------------   ADD STAFF'S INFORMATION PAGE   ----------------");

    printf("\nStaff ID: %d", auto_staff_id());
    sprintf(id, "%d", auto_staff_id());

    printf("\nPassword: 1234\n");
    strcpy(password, "1234");

    getchar();
    while(x){
        printf("\nStaff's Name: ");
        fgets(name,50,stdin); //stdin is use to
        int len = strlen(name);
        if (name[len - 1] == '\n')
            name[len - 1] = '\0';
        if (name[0] != '\0') {
            break;
        } else {
            printf("\nPlease enter Staff Name.\n");
        }
    }
    while (x){
        printf("\nGender (m/f): ");
        scanf("%s", &gender);
        if (strcmp(gender, "m") == 0){
            printf("\nAnnual Leave=8 Days\nCompassionate Leave=2 Days\nEmergency Leave=3 Days\nMedical Leave=14 Days\nMaternity Leave=0 Days\n");
            strcpy(annual_leave, "8");
            strcpy(compassionate_leave, "2");
            strcpy(emergency_leave, "3");
            strcpy(medical_leave, "14");
            strcpy(maternity_leave, "0");
            break;}
        else if (strcmp(gender, "f") == 0){
            printf("\nAnnual Leave=8 Days\nCompassionate Leave=2 Days\nEmergency Leave=3 Days\nMedical Leave=14 Days\nMaternity Leave=98 Days\n");
            strcpy(annual_leave, "8");
            strcpy(compassionate_leave, "2");
            strcpy(emergency_leave, "3");
            strcpy(medical_leave, "14");
            strcpy(maternity_leave, "98");
            break;
        }
        else{
            printf("Please input valid char.\n");}
    }


    printf("\nPlease enter your phone number (exp: 0127332255): ");
    while (scanf("%d", &int_phone_number) != 1) {
        printf("Invalid Input. Please enter valid phone number: ");
        scanf("%*[^\n]");
        //is used to skip the input until the end of the current line in the standard input stream.
        //* character in the format specifier means that the matched characters are read from the input but not stored.
    }

    printf("\nPlease enter your email address: ");
    scanf("%s",email);

    while (x){
        printf("\nPlease select your school of :\n");
        printf("1. School of Computer Science\n");
        printf("2. School of Business\n");
        printf("Enter a number: ");
        scanf("%d",&school_choice);
        switch (school_choice){
        case 1:{
            while (x){
                strcpy(school, "School of Computer Science");
                printf("\n\nPlease select your Department:\n");
                printf("1. Computer Science Department\n");
                printf("2. Engineering Department\n");
                printf("3. Software Engineering Department\n");
                printf("4. Artificial Intelligence Department\n");
                printf("Enter a number: ");
                scanf("%d", &choice_dep);
                switch(choice_dep){
                case 1:
                    strcpy(department, "Computer Science Department");
                    x=false;
                    break;
                case 2:
                    strcpy(department, "Engineering Department");
                    x=false;
                    break;
                case 3:
                    strcpy(department, "Software Engineering Department");
                    x=false;
                    break;
                case 4:
                    strcpy(department, "Artificial Intelligence Department");
                    x=false;
                    break;
                default:
                    printf("Invalid Number.\n");
                }
            }
            break;
        }
        case 2:{
            while (x){
                strcpy(school, "School of Business");
                printf("\n\nPlease select your Department:\n");
                printf("1. Accounting Department\n");
                printf("2. Finance Department\n");
                printf("3. Marketing Department\n");
                printf("4. International Business Department\n");
                printf("Enter a number: ");
                scanf("%d", &choice_dep);
                switch(choice_dep){
                case 1:
                    strcpy(department, "Accounting Department");
                    x=false;
                    break;
                case 2:
                    strcpy(department, "Finance Department");
                    x=false;
                    break;
                case 3:
                    strcpy(department, "Marketing Department");
                    x=false;
                    break;
                case 4:
                    strcpy(department, "International Business Department");
                    x=false;
                    break;
                default:
                    printf("Invalid Number.\n");
                }
            }
            break;
        }
        default:
            printf("Invalid Number.\n");
        }
    }
    strcpy(file_name_id,id);
    strcat(file_name_id,".txt");
    FILE * file = fopen(file_name_id, "a");
    if(file == NULL)
        file = fopen(file_name_id, "w");

    fprintf(file, "%s,%s,%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s\n",
            id,password, name,gender,int_phone_number,email,annual_leave,compassionate_leave,
            emergency_leave,medical_leave,maternity_leave,school,department);
    fprintf(file_id, "%s %s\n", id,password);
    fclose(file);
    fclose(file_id);
    printf("\nStaff information added successfully!\n");
}

void update_leave_balance(){
    char file_staff_id[100];
    char file_staff_password[10];
    char id[10];
    char password[10];
    char name[50];
    char gender[10];
    char email[50];
    char school[1000];
    char department[1000];
    char annual_leave[10];
    char compassionate_leave[10];
    char emergency_leave[10];
    char medical_leave[10];
    char maternity_leave[10];
    char line1[20000];
    char line2[20000];
    int choice_update;
    int int_phone_number;
    bool x=true;

    while (x){
        printf("\n\n---------------------------------------------   Update Leave Record   --------------------------------------------\n\n");
        printf("\n1.Update leave balance for all staff (Yearly update)\n2.Update leave balance for specific staff\n\nEnter a number:");
        scanf("%d", &choice_update);
        switch (choice_update) {
            case 1: {
                FILE *file_id = fopen("staff_id.txt", "r");   //open staff id file  to open staff information file
                if (file_id == NULL) {
                    printf("Not able to open existing file, creating new file\n");
                    break;}

                while (fgets(line1, 20000, file_id) != NULL)
                {
                    FILE * fp_tmp = fopen("tmp.txt", "w");

                    sscanf(line1, "%s %s", file_staff_id, file_staff_password);
                    strcat(file_staff_id, ".txt");

                    FILE *fp;
                    fp = fopen(file_staff_id, "r");
                    if (fp == NULL)
                        {printf("Error opening file\n");
                        exit(0);}

                     while (fgets(line2, sizeof(line2), fp) != EOF)
                    {
                        sscanf(line2, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                               id, password, name, gender, &int_phone_number, email, annual_leave, compassionate_leave,
                               emergency_leave, medical_leave,
                               maternity_leave,school, department);
                        //specifies that characters should be read until a comma is encountered, but the comma should not be stored.

                        if (strcmp(gender, "m") == 0) {
                            strcpy(annual_leave, "8");
                            strcpy(compassionate_leave, "2");
                            strcpy(emergency_leave, "3");
                            strcpy(medical_leave, "14");
                            strcpy(maternity_leave, "0");

                            fprintf(fp_tmp, "%s,%s,%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s\n",
                                    id,password, name,gender,int_phone_number,email,annual_leave,compassionate_leave,
                                    emergency_leave,medical_leave,maternity_leave,school,department);

                            printf("\n\n------------------------- %s's New Leave balance   ----------------------------------------------\n",name);
                            printf("\nAnnual Leave        : %s Days",annual_leave);
                            printf("\nCompassionate Leave : %s Days",compassionate_leave);
                            printf("\nEmergency Leave     : %s Days",emergency_leave);
                            printf("\nMedical Leave       : %s Days",medical_leave);
                            printf("\nMaternity Leave     : %s Days",maternity_leave);
                            printf("\n\nSuccessful Updated.\n");
                            break;}

                        else if (strcmp(gender, "f") == 0) {
                            strcpy(annual_leave, "8");
                            strcpy(compassionate_leave, "2");
                            strcpy(emergency_leave, "3");
                            strcpy(medical_leave, "14");
                            strcpy(maternity_leave, "98");

                            fprintf(fp_tmp, "%s,%s,%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s\n",
                                    id,password, name,gender,int_phone_number,email,annual_leave,compassionate_leave,
                                    emergency_leave,medical_leave,maternity_leave,school,department);

                            printf("\n\n------------------------- %s's New Leave balance   ----------------------------------------------\n",name);
                            printf("\nAnnual Leave        : %s Days",annual_leave);
                            printf("\nCompassionate Leave : %s Days",compassionate_leave);
                            printf("\nEmergency Leave     : %s Days",emergency_leave);
                            printf("\nMedical Leave       : %s Days",medical_leave);
                            printf("\nMaternity Leave     : %s Days",maternity_leave);
                            printf("\n\nSuccessful Updated.\n");
                            break;}
                    }
                    fclose(fp);
                    fclose(fp_tmp);
                    remove(file_staff_id);
                    rename("tmp.txt",file_staff_id);
                }
                fclose(file_id);
                x=false;
                break;
            } //case 1

        case 2: {
            bool found=true,found_1=false;
            char modify_id[10];

            FILE * fp_tmp = fopen("tmp.txt", "w");

            printf("Enter the staff ID that needs to modify leave balance: ");
            scanf("%s",&modify_id);

            FILE *file_id = fopen("staff_id.txt", "r");
            if (file_id == NULL) {
                printf("Not able to open existing file, creating new file\n");
                break;}

            while (fgets(line1, 20000, file_id) != NULL)
            {
                sscanf(line1, "%s %s", file_staff_id, file_staff_password);

                if (strcmp(file_staff_id,modify_id)==0){
                    found=false;
                    found_1=true;
                    strcat(file_staff_id, ".txt");

                    FILE *fp;
                    fp = fopen(file_staff_id, "r");
                    if (fp == NULL)
                    {printf("Error opening file\n");
                        exit(0);}

                     while (fgets(line2, sizeof(line2), fp) != EOF)
                    {
                        sscanf(line2, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                               id, password, name, gender,&int_phone_number,email, annual_leave, compassionate_leave, emergency_leave, medical_leave,
                               maternity_leave,school, department);

                        printf("\n\n----------------------------------   Original Leave balance   ------------------------------------------\n\n");
                        printf("ID                  : %s\n"
                               "Password            : %s\n"
                               "Name                : %s\n"
                               "Gender              : %s\n"
                               "Phone Number        : %d\n"
                               "Email Address       : %s\n"
                               "School              : %s\n"
                               "Department          : %s\n"
                               "Annual Leave        : %s Days\n"
                               "Compassionate Leave : %s Days\n"
                               "Emergency Leave     : %s Days\n"
                               "Medical Leave       : %s Days\n"
                               "Maternity Leave     : %s Days\n",
                               id, password, name, gender, int_phone_number, email,school,department, annual_leave, compassionate_leave,
                               emergency_leave, medical_leave, maternity_leave);

                        if (strcmp(gender, "m") == 0) {
                            strcpy(annual_leave, "8");
                            strcpy(compassionate_leave, "2");
                            strcpy(emergency_leave, "3");
                            strcpy(medical_leave, "14");
                            strcpy(maternity_leave, "0");

                            fprintf(fp_tmp, "%s,%s,%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s\n",
                                    id,password, name,gender,int_phone_number,email,annual_leave,compassionate_leave,
                                    emergency_leave,medical_leave,maternity_leave,school,department);

                            printf("\n------------------------------------   New Leave balance   --------------------------------------------\n");
                            printf("\nAnnual Leave        : %s Days",annual_leave);
                            printf("\nCompassionate Leave : %s Days",compassionate_leave);
                            printf("\nEmergency Leave     : %s Days",emergency_leave);
                            printf("\nMedical Leave       : %s Days",medical_leave);
                            printf("\nMaternity Leave     : %s Days",maternity_leave);
                            printf("\n\nSuccessful Updated.\n");
                            break;}

                        else if (strcmp(gender, "f") == 0) {
                            strcpy(annual_leave, "8");
                            strcpy(compassionate_leave, "2");
                            strcpy(emergency_leave, "3");
                            strcpy(medical_leave, "14");
                            strcpy(maternity_leave, "98");

                            fprintf(fp_tmp, "%s,%s,%s,%s,%d,%s,%s,%s,%s,%s,%s,%s,%s\n",
                                    id,password, name,gender,int_phone_number,email,annual_leave,compassionate_leave,
                                    emergency_leave,medical_leave,maternity_leave,school,department);

                            printf("------------------------------------   New Leave balance   --------------------------------------------\n");
                            printf("\nAnnual Leave        : %s Days",annual_leave);
                            printf("\nCompassionate Leave : %s Days",compassionate_leave);
                            printf("\nEmergency Leave     : %s Days",emergency_leave);
                            printf("\nMedical Leave       : %s Days",medical_leave);
                            printf("\nMaternity Leave     : %s Days",maternity_leave);
                            printf("\n\nSuccessful Updated.\n");
                            break;}

                    }
                fclose(fp);
                }
                if (found_1)
                    break;
            }
            if (found)
                printf("\nDo not have this staff id.\n");
            fclose(file_id);
            fclose(fp_tmp);
            remove(file_staff_id);
            rename("tmp.txt",file_staff_id);
            x=false;
            break;
            } //case 2
        default:
            printf("\nInvalid Number.");
            break;
        } // switch
    }
}

int leap_year(int year) {
    //if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    if (year % 4 == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

int days_in_month(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return (leap_year(year) ? 29 : 28);
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

int count_leave_days(int startDay, int startMonth, int startYear, int endDay, int endMonth, int endYear) {

    if (endDay==0 && endMonth==0 && endYear==0){
        return 1;
    }
    else {
        int totalDays = 0;
        int daysInStartMonth = days_in_month(startMonth, startYear);
        totalDays += (daysInStartMonth - startDay + 1);

        if (startMonth == endMonth ){
            int daysInEndMonth = days_in_month(endMonth, endYear);
            int x= daysInEndMonth - endDay;
            totalDays-=x;
        }

        int currentMonth = startMonth + 1;  // if enddate >2month will run this loop
        while (currentMonth < endMonth ) {
            totalDays += days_in_month(currentMonth, startYear);
            currentMonth++;}

        if (startMonth != endMonth){
            for (int i = 1; i <= endDay; i++) {
            totalDays++;}
        }

        for (int i = startYear ; i < endYear; i++) {
            totalDays += leap_year(i) ? 366 : 365;}

        return totalDays;
    }
}

void current_date(int *day, int *month, int *year) {
    time_t t;
    struct tm *local;

    // Get the current time
    t = time(NULL);

    // Convert the current time to local time
    local = localtime(&t);

    // Update the day, month, and year variables
    *day = local->tm_mday;
    //the value of the tm_mday field of the local struct is assigned to the variable pointed to by day.
    *month = local->tm_mon;
    *year = local->tm_year;
    //-> operator is used with pointers to variables.
}

void apply_leave(){
    int choice_leave;
    bool x=true;

    char line[MAX_LINE_LENGTH];

    //staff inform
    char id[10];
    char password[10];
    char name[50];
    char gender[5];
    int int_phone_number;
    char email[10];
    char annual_leave[10];
    char compassionate_leave[10];
    char emergency_leave[10];
    char medical_leave[10];
    char maternity_leave[10];
    char school[1000];
    char department[1000];

    // apply leave inform
    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
    int totalDays;
    char leave_type[10000];
    char leave_reason[10000];
    char leave_status[1000];

    strcpy(file_staff_id,login_id);
    strcat(file_staff_id, ".txt");

    FILE *file;
    file = fopen(file_staff_id, "r");
    if (file == NULL)
    {
        printf("Error opening %s file\n",file_staff_id);
        exit(0);
    }

    while (fgets(line, sizeof(line), file) != NULL)      // staff infor file
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
               id, password, name, gender, &int_phone_number,email, annual_leave, compassionate_leave, emergency_leave, medical_leave,
               maternity_leave, school,department);

    printf("\n-------------------------   Apply Leave Page   ----------------------------------------------\n");

    printf("\nName       : %s",name);
    printf("\nGender     : %s",gender);
    printf("\nSchool     : %s",school);
    printf("\nDepartment : %s",department);

    printf("\n\n------------------------- %s Leave Balance ----------------------------------------------\n",name);

    printf("\nAnnual Leave        : %s Days",annual_leave);
    printf("\nCompassionate Leave : %s Days",compassionate_leave);
    printf("\nEmergency Leave     : %s Days",emergency_leave);
    printf("\nMedical Leave       : %s Days",medical_leave);
    printf("\nMaternity Leave     : %s Days",maternity_leave);

    printf("\n\n--------------------------------------------------------------------------------------------\n");

    if (strcmp(gender,"f")==0){
        while (x){
            printf("\nLeave Type: \n");
            printf("1.Annual Leave\n");
            printf("2.Compassionate Leave\n");
            printf("3.Emergency Leave\n");
            printf("4.Medical Leave\n");
            printf("5.Maternity Leave\n");
            printf("\nEnter a number: ");
            scanf("%d", &choice_leave);

            switch(choice_leave){
            case 1:
                strcpy(leave_type, "Annual Leave");
                x=false;
                break;
            case 2:
                strcpy(leave_type, "Compassionate Leave");
                x=false;
                break;
            case 3:
                strcpy(leave_type, "Emergency Leave");
                x=false;
                break;
            case 4:
                strcpy(leave_type, "Medical Leave");
                x=false;
                break;
            case 5:
                strcpy(leave_type, "Maternity Leave");
                x=false;
            default:
                printf("\nInvalid option.\n");
                break;
            }
        }
    }
    else if(strcmp(gender,"m")==0){
        while (x){
            printf("\nLeave Type: \n");
            printf("1.Annual Leave\n");
            printf("2.Compassionate Leave\n");
            printf("3.Emergency Leave\n");
            printf("4.Medical Leave\n");
            printf("\nEnter a number: ");
            scanf("%d", &choice_leave);

            switch(choice_leave){
            case 1:
                strcpy(leave_type, "Annual Leave");
                x=false;
                break;
            case 2:
                strcpy(leave_type, "Compassionate Leave");
                x=false;
                break;
            case 3:
                strcpy(leave_type, "Emergency Leave");
                x=false;
                break;
            case 4:
                strcpy(leave_type, "Medical Leave");
                x=false;
                break;
            default:
                printf("\nInvalid option.\n");
                break;
            }
        }
    }

    x=true;
    int day, month, year;
    int current_day=0;
    current_date(&day, &month, &year);
    month++;
    year=year+1900;
    current_day=year*10000+month*100+day;
    while (x){
        printf("\nEnter the START date you need to apply (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &startDay, &startMonth, &startYear);

        int start_day=0;
        start_day=startYear*10000+startMonth*100+startDay;

        if (startMonth==1 && startDay>=1 && startDay<=31) {
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==2 && startDay>=1 && startDay<=28){\
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==3 && startDay>=1 && startDay<=31 ){
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==4 && startDay>=1 && startDay<=30 ){
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==5 && startDay>=1 && startDay<=31){
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==6 && startDay>=1 && startDay<=30 ){
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==7 && startDay>=1 && startDay<=31){
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==8 && startDay>=1 && startDay<=31 ){
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==9 && startDay>=1 && startDay<=30){
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==10 && startDay>=1 && startDay<=31){
           if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==11 && startDay>=1 && startDay<=30 ){
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else if (startMonth==12 && startDay>=1 && startDay<=31){
            if (start_day > current_day+10000)
                printf("\nYou cannot apply for leave beyond one year in advance\n");
            else{
                if (start_day>current_day)
                    break;
                else
                    printf("\nPlease enter a date after today.\n");
            }
        }
        else
            printf("\nInvalid Date.\n");
    }

    x=true;
    while (x){
        printf("\nEnter the END date (dd/mm/yyyy),if none PLS input 0/0/0: ");
        scanf("%d/%d/%d", &endDay, &endMonth, &endYear);

        int start_day=0;
        start_day=startYear*10000+startMonth*100+startDay;
        int end_day=0;
        end_day=endYear*10000+endMonth*100+endDay;

        if (endMonth==1 && endDay>=1 && endDay<=31 ){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==2 && endDay>=1 && endDay<=28 ){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==3 && endDay>=1 && endDay<=31){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==4 && endDay>=1 && endDay<=30){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==5 && endDay>=1 && endDay<=31 ){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==6 && endDay>=1 && endDay<=30 ){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==7 && endDay>=1 && endDay<=31 ){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==8 && endDay>=1 && endDay<=31){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.");
        }
        else if (endMonth==9 && startDay>=1 && startDay<=30 ){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==10 && endDay>=1 && endDay<=31){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==11 && endDay>=1 && endDay<=30){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==12 && endDay>=1 && endDay<=311){
            if (end_day>start_day || end_day==0)
                break;
            else
                printf("\nInput a date after apply start day.\n");
        }
        else if (endMonth==0 && endDay==0 && endDay==0)
            break;
        else
            printf("\nInvalid Date.It is not possible to apply for leave after 2 years in advance.\n");
    }

    totalDays = count_leave_days(startDay, startMonth, startYear, endDay, endMonth, endYear);
    printf("\nTotal Apply  Leave Days: %d\n", totalDays);

    x=true;
    getchar();
    while (x) {
        printf("\nLeave reason describe: ");
        fgets(leave_reason, 10000, stdin);
        int len = strlen(leave_reason);
        if (leave_reason[len - 1] == '\n') {
            leave_reason[len - 1] = '\0';
        }
        if (leave_reason[0] != '\0') {
            break;
        } else {
            printf("\nPlease enter leave reason.\n");
        }
    }


    printf("\nLeave Status: IN APPLICATION\n");
    strcpy(leave_status, "IN APPLICATION");

    FILE * file_1 = fopen("staff_apply_leave.txt", "a");
    if(file_1 == NULL){
        file_1 = fopen("staff_apply_leave.txt", "w");
    }

    fprintf(file_1, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s\n",
        id,password, name,gender,school,department,leave_type,
        startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);
    printf("\nSuccessful Apply. Waiting for approve.\n");

    fclose(file_1);
    }
    fclose(file);
}

void leave_approve(){
    bool found=true,x=true;

    char id[20];
    char password[20];
    char name[50];
    char gender[10];
    char school [1000];
    char department[1000];
    char leave_type[10000];
    char leave_reason[10000];
    char leave_status[1000];
    char line[20000];
    char choice_approve[100];

    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
    int totalDays;

    FILE *file = fopen("staff_apply_leave.txt", "r");
    if (file == NULL) {
        printf("Not able to open staff_apply_leave.txt, creating new file\n");}

    FILE * fp_tmp = fopen("tmp.txt", "a");
        if (fp_tmp == NULL) {
            fp_tmp = fopen("tmp.txt", "w");
            exit(0);  }

    while (fgets(line, 20000, file) != NULL){
        x=true;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%[^,],%[^\n]",
        id,password, name,gender,school,department,leave_type,
        &startDay, &startMonth, &startYear,&endDay, &endMonth, &endYear,&totalDays,leave_reason,leave_status);

        if (strcmp(leave_status,"IN APPLICATION")==0){
            found=false;

            printf("\n-------------------------   Staff application leave information   -------------------------------------\n");
            printf("\nStaff ID           : %s",id);
            printf("\nName               : %s",name);
            printf("\nGender             : %s",gender);
            printf("\nDeparment          : %s",department);
            printf("\nLeave Type         : %s",leave_type);
            printf("\nTotal Apply Days   : %d",totalDays);
            printf("\nLeave Reason       : %s",leave_reason);
            printf("\nLeave started day  : %d/%d/%d",startDay,startMonth,startYear);
            printf("\nLeave end day      : %d/%d/%d",endDay,endMonth,endYear);

            printf("\n\n--------------------------------------   %s Leave Balance   ----------------------------------------------\n\n",name);

            char line1[20000];
            char id_1[10];
            char password_1[10];
            char name_1[50];
            char gender_1[10];
            int int_phone_number;
            char email[50];
            int annual_leave;
            int compassionate_leave;
            int emergency_leave;
            int medical_leave;
            int maternity_leave;
            char school_1[1000];
            char department_1[1000];
            char id_txt[100];

            strcpy(id_txt,id);
            strcat(id_txt,".txt");

            FILE *file_1 = fopen(id_txt, "r");
            if (file_1 == NULL) {
                printf("Not able to open %s, creating new file\n",id_txt);
                break;}

            while (fgets(line1, 20000, file_1) != NULL){
                sscanf(line1, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%d,%d,%d,%d,%d,%[^,],%[^\n]",
                       id_1, password_1, name_1, gender_1,&int_phone_number,email, &annual_leave,
                       &compassionate_leave, &emergency_leave, &medical_leave,
                       &maternity_leave,school_1,department_1);

                printf("Annual Leave         : %d\n"
                       "Compassionate Leave  : %d\n"
                       "Emergency Leave      : %d\n"
                       "Medical Leave        : %d\n"
                       "Maternity Leave      : %d\n\n",
                       annual_leave, compassionate_leave, emergency_leave, medical_leave,maternity_leave);
                printf("\n-------------------------------------------------------------------------------------------------\n");
            }


            while(x){
                printf("\nPlease enter (yes) %s's leave is approved, enter (no) is not approved the leave.",name);
                printf("\nEnter (cd) to see the number of people who have taken leave for the day.");
                printf("\nEnter (yes/no/cd):");
                scanf("%s", choice_approve);

                if (strcmp(choice_approve,"yes")==0){
                    x=false;
                    FILE *file_tmp = fopen("tmp1.txt", "w");

                    strcpy(leave_status, "APPROVED");

                    if (strcmp(leave_type,"Annual Leave")==0){
                        annual_leave=annual_leave-totalDays; }
                    else if (strcmp(leave_type,"Compassionate Leave")==0){
                        compassionate_leave=compassionate_leave-totalDays; }
                    else if (strcmp(leave_type,"Emergency Leave")==0){
                        emergency_leave=emergency_leave-totalDays; }
                    else if (strcmp(leave_type,"Medical Leave")==0){
                        medical_leave=medical_leave-totalDays; }
                    else if (strcmp(leave_type,"Maternity Leave")==0){
                        maternity_leave=maternity_leave-totalDays; }

                    fprintf(fp_tmp, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s\n",
                        id,password, name,gender,school,department,leave_type,
                        startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);

                    fprintf(file_tmp, "%s,%s,%s,%s,%d,%s,%d,%d,%d,%d,%d,%s,%s\n",
                            id_1,password_1, name_1,gender_1,int_phone_number,email,annual_leave,compassionate_leave,
                            emergency_leave,medical_leave,maternity_leave,school_1,department_1);

                    fclose(file_tmp);
                    fclose(file_1);
                    remove(id_txt);
                    rename("tmp1.txt",id_txt);
                }
                else if (strcmp(choice_approve,"no")==0){
                    x=false;
                    strcpy(leave_status, "REJECT");
                    fprintf(fp_tmp, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s\n",
                        id,password, name,gender,school,department,leave_type,
                        startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);
                }
                else if (strcmp(choice_approve,"cd")==0){
                    char line2[20000];

                    char id[20];
                    char password[20];
                    char name[50];
                    char gender[10];
                    char school[1000];
                    char department[1000];
                    char leave_type[10000];
                    char leave_reason[10000];
                    char leave_status[1000];
                    char choice_approve[100];
                    int startDay, startMonth, startYear;
                    int endDay, endMonth, endYear;
                    int totalDays;

                    int input_Day;
                    int input_Month;
                    int input_Year;
                    int whole_input_date;

                    int approve_1=0,approve_2=0;
                    int in_application_1=0,in_application_2=0;
                    int reject_1=0,reject_2=0;
                    bool x=true;

                    while(x){
                        printf("\nInput Day/Month/Year:");
                        scanf("%d/%d/%d",&input_Day,&input_Month,&input_Year);
                        if (input_Month==1 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
                            break;
                        else if (input_Month==2 && input_Day>=1 && input_Day<=28 && input_Year!=NULL)
                            break;
                        else if (input_Month==3 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
                            break;
                        else if (input_Month==4 && input_Day>=1 && input_Day<=30 && input_Year!=NULL)
                            break;
                        else if (input_Month==5 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
                            break;
                        else if (input_Month==6 && input_Day>=1 && input_Day<=30 && input_Year!=NULL)
                            break;
                        else if (input_Month==7 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
                            break;
                        else if (input_Month==8 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
                            break;
                        else if (input_Month==9 && input_Day>=1 && input_Day<=30 && input_Year!=NULL)
                            break;
                        else if (input_Month==10 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
                            break;
                        else if (input_Month==11 && input_Day>=1 && input_Day<=30 && input_Year!=NULL)
                            break;
                        else if (input_Month==12 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
                            break;
                        else
                            printf("\nInvalid Date.");

                    }

                    whole_input_date=input_Year*10000+input_Month*100+input_Day;


                    FILE *file_2 = fopen("staff_apply_leave.txt", "r");
                    if (file_2 == NULL) {
                        printf("Not able to open staff_apply_leave.txt, creating new file\n");}

                    while (fgets(line2, 20000, file_2) != NULL){

                        sscanf(line2, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%[^,],%[^\n]",
                                id,password, name,gender,school,department,leave_type,
                                &startDay, &startMonth, &startYear,&endDay, &endMonth, &endYear,&totalDays,leave_reason,leave_status);

                        int start_day=0;
                        int end_day=0;
                        start_day=startYear*10000+startMonth*100+startDay;
                        end_day=endYear*10000+endMonth*100+endDay;

                        if ((whole_input_date >= start_day)&&(whole_input_date <= end_day))
                        {
                            if (strcmp(leave_status,"APPROVED")==0){
                                approve_1++;
                            }
                            else if (strcmp(leave_status,"IN APPLICATION")==0){
                                in_application_1++;
                            }
                            else if (strcmp(leave_status,"REJECT")==0){
                                reject_1++;
                            }

                        }
                        else if ((whole_input_date == start_day) && (end_day==0)){

                            if (strcmp(leave_status,"APPROVED")==0) {
                                approve_2++;
                            }
                            else if (strcmp(leave_status,"IN APPLICATION")==0){
                                in_application_2++;
                            }
                            else if (strcmp(leave_status,"REJECT")==0){
                                reject_2++;
                            }
                        }
                    }
                    int total=approve_1+approve_2;
                    printf("\nTotal APPROVED Staff: %d",total);
                    int total2=in_application_1+in_application_2;
                    printf("\n\nTotal IN APPLICATION Staff: %d",total2);
                    int total3=reject_1+reject_2;
                    printf("\n\nTotal IN REJECT Staff: %d\n",total3);
                    printf("\n-------------------------------------------------------------------------------------------------\n");
                    x=false;
                    fclose(file_2);
                }
            }
        }
        else {
            fprintf(fp_tmp, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s\n",
                    id,password, name,gender,school,department,leave_type,
                    startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);}
    }
    if (found)
        printf("\nNo staff apply leave.");

    fclose(file);
    fclose(fp_tmp);

    remove("staff_apply_leave.txt");
    rename("tmp.txt", "staff_apply_leave.txt");
}

void search_date(){
    char line[20000];

    char id[20];
    char password[20];
    char name[50];
    char gender[10];
    char school[1000];
    char department[1000];
    char leave_type[10000];
    char leave_reason[10000];
    char leave_status[1000];
    char choice_approve[100];
    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
    int totalDays;

    int input_Day;
    int input_Month;
    int input_Year;
    int whole_input_date;

    int approve_1=0,approve_2=0;
    int in_application_1=0,in_application_2=0;
    int reject_1=0,reject_2=0;
    bool x=true;

    while(x){
        printf("\nInput Day/Month/Year:");
        scanf("%d/%d/%d",&input_Day,&input_Month,&input_Year);
        if (input_Month==1 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
            break;
        else if (input_Month==2 && input_Day>=1 && input_Day<=28 && input_Year!=NULL)
            break;
        else if (input_Month==3 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
            break;
        else if (input_Month==4 && input_Day>=1 && input_Day<=30 && input_Year!=NULL)
            break;
        else if (input_Month==5 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
            break;
        else if (input_Month==6 && input_Day>=1 && input_Day<=30 && input_Year!=NULL)
            break;
        else if (input_Month==7 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
            break;
        else if (input_Month==8 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
            break;
        else if (input_Month==9 && input_Day>=1 && input_Day<=30 && input_Year!=NULL)
            break;
        else if (input_Month==10 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
            break;
        else if (input_Month==11 && input_Day>=1 && input_Day<=30 && input_Year!=NULL)
            break;
        else if (input_Month==12 && input_Day>=1 && input_Day<=31 && input_Year!=NULL)
            break;
        else
            printf("\nInvalid Date.");
    }

    whole_input_date=input_Year*10000+input_Month*100+input_Day;

    FILE *file = fopen("staff_apply_leave.txt", "r");
    if (file == NULL) {
        printf("Not able to open staff_apply_leave.txt, creating new file\n");}

    while (fgets(line, 20000, file) != NULL){

        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%[^,],%[^\n]",
                id,password, name,gender,school,department,leave_type,
                &startDay, &startMonth, &startYear,&endDay, &endMonth, &endYear,&totalDays,leave_reason,leave_status);

        int start_day=0;
        int end_day=0;
        start_day=startYear*10000+startMonth*100+startDay;
        end_day=endYear*10000+endMonth*100+endDay;

        if ((whole_input_date >= start_day)&&(whole_input_date <= end_day))
        {
            printf("\n\n-------------------------------------------------------------------------------------------------\n\n");
            printf("ID              : %s\n",id);
            printf("Name            : %s\n",name);
            printf("Gender          : %s\n",gender);
            printf("School          : %s\n",school);
            printf("Department      : %s\n",department);
            printf("Leave Type      : %s\n",leave_type);
            printf("Leave Start Day : %d/%d/%d\n",startDay, startMonth, startYear);
            printf("Leave End Day   : %d/%d/%d\n",endDay, endMonth, endYear);
            printf("Total Leave Day : %d\n",totalDays);
            printf("Leave Reason    : %s\n",leave_reason);
            printf("Leave Status    : %s\n",leave_status);

            if (strcmp(leave_status,"APPROVED")==0){
                approve_1++;
            }
            else if (strcmp(leave_status,"IN APPLICATION")==0){
                in_application_1++;
            }
            else if (strcmp(leave_status,"REJECT")==0){
                reject_1++;
            }

        }
        else if ((whole_input_date == start_day) && (end_day==0)){

            printf("\n\n-------------------------------------------------------------------------------------------------\n\n");
            printf("ID              : %s\n",id);
            printf("Name            : %s\n",name);
            printf("Gender          : %s\n",gender);
            printf("School          : %s\n",school);
            printf("Department      : %s\n",department);
            printf("Leave Type      : %s\n",leave_type);
            printf("Leave Start Day : %d/%d/%d\n",startDay, startMonth, startYear);
            printf("Leave End Day   : %d/%d/%d\n",endDay, endMonth, endYear);
            printf("Total Leave Day : %d\n",totalDays);
            printf("Leave Reason    : %s\n",leave_reason);
            printf("Leave Status    : %s\n",leave_status);

            if (strcmp(leave_status,"APPROVED")==0) {
                approve_2++;
            }
            else if (strcmp(leave_status,"IN APPLICATION")==0){
                in_application_2++;
            }
            else if (strcmp(leave_status,"REJECT")==0){
                reject_2++;
            }
        }
    }
    fclose(file);
    printf("\n\n-------------------------------------------------------------------------------------------------\n\n");

    int total=approve_1+approve_2;
    printf("\nTotal APPROVED Staff: %d",total);
    int total2=in_application_1+in_application_2;
    printf("\n\nTotal IN APPLICATION Staff: %d",total2);
    int total3=reject_1+reject_2;
    printf("\n\nTotal IN REJECT Staff: %d\n",total3);

}

void staff_check_leave_status(){
    char id[20];
    char password[20];
    char name[50];
    char gender[10];
    char school[1000];
    char department[1000];
    char leave_type[10000];
    char leave_reason[10000];
    char leave_status[1000];
    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
    int totalDays;

    int i=1;
    char line1[20000];
    bool found=true;

    FILE *file = fopen("staff_apply_leave.txt", "r");
    if (file == NULL) {
        printf("Not able to open staff_apply_leave , creating new file\n");}

    while (fgets(line1, 20000, file) != NULL){
        sscanf(line1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%[^,],%[^\n]",
                id,password, name,gender,school,department,leave_type,
                &startDay, &startMonth, &startYear,&endDay, &endMonth, &endYear,&totalDays,leave_reason,leave_status);

        if (strcmp(login_id,id)==0){
            found=false;
            printf("\n\n---------------------------------   %s Leave Status %d   -----------------------------------------------\n\n",name,i);
            printf("ID              : %s\n",id);
            printf("Name            : %s\n",name);
            printf("Gender          : %s\n",gender);
            printf("School          : %s\n",school);
            printf("Department      : %s\n",department);
            printf("Leave Type      : %s\n",leave_type);
            printf("Leave Start Day : %d/%d/%d\n",startDay, startMonth, startYear);
            printf("Leave End Day   : %d/%d/%d\n",endDay, endMonth, endYear);
            printf("Total Leave Day : %d\n",totalDays);
            printf("Leave Reason    : %s\n",leave_reason);
            printf("Leave Status    : %s\n",leave_status);
            i++;
        }
    }
    if (found)
        printf("\nYou dont have apply any leave.\n");
    fclose(file);
}

void staff_check_leave_information(){
    char id[20];
    char password[20];
    char name[50];
    char gender[10];
    char school[1000];
    char department[1000];
    char leave_type[10000];
    char leave_reason[10000];
    char leave_status[1000];
    char startDay[10], startMonth[10], startYear[10];
    char endDay[10], endMonth[10], endYear[10];
    char totalDays[10];
    char line1[20000];
    char line2[20000];
    char line3[20000];

    int int_phone_number;
    char email[50];
    int annual_leave;
    int compassionate_leave;
    int emergency_leave;
    int medical_leave;
    int maternity_leave;

    bool found=true;
    char id_txt[100];

    printf("\n\n---------------------------------   Original Leave Days Per Year   ------------------------------------\n\n");
    printf("Annual Leave        :8  Days\n"
           "Compassionate Leave :2  Days\n"
           "Emergency Leave     :3  Days\n"
           "Medical Leave       :14 Days\n"
           "Maternity Leave (M) :0  Days\n"
           "Maternity Leave (F) :98  Days\n");

    printf("\n\n----------------------------------------   Approved Leave  ---------------------------------------------\n\n");

    int no=1;
    FILE *file = fopen("staff_apply_leave.txt", "r");
    if (file == NULL) {
        printf("Not able to open staff_apply_leave , creating new file\n");}

    while (fgets(line1, 20000, file) != NULL){
        sscanf(line1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                id,password, name,gender,school,department,leave_type,
                startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);

        if (strcmp(login_id,id)==0){
            if (strcmp(leave_status,"APPROVED")==0){
                printf("\nNO.%d\n",no);
                printf("START DAY    : %s/%s/%s\n",startDay, startMonth, startYear);
                printf("END DAY      : %s/%s/%s\n",endDay, endMonth, endYear);
                printf("LEAVE TYPE   : %s\n",leave_type);
                printf("TOTAL DAYS   : %s\n",totalDays);
                printf("LEAVE REASON : %s\n",leave_reason);
                printf("LEAVE STATUS : %s\n",leave_status);
                found=false;
                no++;
            }
        }
    }
    if (found)
        printf("NONE\n");

    printf("\n\n----------------------------------------   Balance Leave  ----------------------------------------------\n\n");

    strcpy(id_txt,login_id);
    strcat(id_txt,".txt");

    FILE *file_2 = fopen(id_txt, "r");
    if (file_2 == NULL) {
        printf("Not able to open %s, creating new file\n",id_txt);}

    while (fgets(line2, 20000, file_2) != NULL){
        sscanf(line2, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%d,%d,%d,%d,%d,%[^,],%[^\n]",
               id, password, name, gender,&int_phone_number,email, &annual_leave, &compassionate_leave, &emergency_leave, &medical_leave,
               &maternity_leave,school, department);

        if (strcmp(login_id,id)==0){
            printf("Annual Leave        : %d  Days\n"
                   "Compassionate Leave : %d  Days\n"
                   "Emergency Leave     : %d  Days\n"
                   "Medical Leave       : %d Days\n"
                   "Maternity Leave     : %d Days\n",
                   annual_leave, compassionate_leave, emergency_leave, medical_leave,maternity_leave);
        }
    }
    printf("\n\n----------------------------------------   Pending Leave  ----------------------------------------------\n\n");

    found=true;
    no=1;

    FILE *file_3 = fopen("staff_apply_leave.txt", "r");
    if (file_3 == NULL) {
        printf("Not able to open staff_apply_leave , creating new file\n");}

    while (fgets(line3, 20000, file_3) != NULL){
        sscanf(line3, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                id,password, name,gender,school,department,leave_type,
                startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);

        if (strcmp(login_id,id)==0){

            if (strcmp(leave_status,"IN APPLICATION")==0){

                printf("\nNO.%d\n",no);
                printf("START DAY    : %s/%s/%s\n",startDay, startMonth, startYear);
                printf("END DAY      : %s/%s/%s\n",endDay, endMonth, endYear);
                printf("LEAVE TYPE   : %s\n",leave_type);
                printf("TOTAL DAYS   : %s\n",totalDays);
                printf("LEAVE REASON : %s\n",leave_reason);
                printf("LEAVE STATUS : %s\n",leave_status);
                found=false;
                no++;
            }
        }
    }
    if (found)
        printf("NONE\n");

    fclose(file);
    fclose(file_2);
    fclose(file_3);
}

void admin_check_leave_information(){
    char id[20];
    char password[20];
    char name[50];
    char gender[10];
    char school[1000];
    char department[1000];
    char leave_type[10000];
    char leave_reason[10000];
    char leave_status[1000];
    char choice_approve[100];
    char startDay[10], startMonth[10], startYear[10];
    char endDay[10], endMonth[10], endYear[10];
    char totalDays[10];
    char line1[30000];
    char line2[30000];

    int int_phone_number;
    char email[50];
    int annual_leave;
    int compassionate_leave;
    int emergency_leave;
    int medical_leave;
    int maternity_leave;

    bool found=true,x=true;
    char id_txt[100];
    char input_id[10];
    char staff_id[10];
    char staff_pass[10];

    while (x){
        printf("\nInput Staff ID to search Staff Leave Information: ");
        scanf("%s",input_id);

        FILE *file_5 = fopen("staff_id.txt", "r");
        if (file_5 == NULL)
            printf("Error opening staff_id.txt file\n");

        while (fgets(line2, MAX_LINE_LENGTH, file_5) != NULL) {
            sscanf(line2, "%s %s", staff_id, staff_pass);
            if (strcmp(input_id, staff_id) == 0 ){
                x=false;
                found=false;
                break;
            }
        }
        if (found)
            printf ("\nPlease enter valid Staff ID.\n");
            continue;
        fclose(file_5);
    }
    found=true;
    printf("\n\n---------------------------------   Staff Information   ------------------------------------\n\n");

    strcpy(id_txt,input_id);
    strcat(id_txt,".txt");

    FILE *file_4 = fopen(id_txt, "r");
    if (file_4 == NULL) {
        printf("Not able to open %s , creating new file\n",id_txt );}

    while (fgets(line1, sizeof(line1), file_4) != NULL){
        sscanf(line1, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%d,%d,%d,%d,%d,%[^,],%[^\n]",
                id, password, name, gender,&int_phone_number,email, &annual_leave, &compassionate_leave, &emergency_leave, &medical_leave,
               &maternity_leave,school, department);
        if (strcmp(input_id,id)==0){
            printf("\nName       : %s",name);
            printf("\nGender     : %s",gender);
            printf("\nSchool     : %s",school);
            printf("\nDepartment : %s\n",department);
            break;
        }
    }

    printf("\n\n---------------------------------   Original Leave Days Per Year   ------------------------------------\n\n");
    printf("Annual Leave        :8  Days\n"
           "Compassionate Leave :2  Days\n"
           "Emergency Leave     :3  Days\n"
           "Medical Leave       :14 Days\n"
           "Maternity Leave (M) :0  Days\n"
           "Maternity Leave (F) :98  Days\n");

    printf("\n\n----------------------------------------   Approved Leave  ---------------------------------------------\n\n");

    int no=1;
    FILE *file = fopen("staff_apply_leave.txt", "r");
    if (file == NULL){
        printf("Not able to open staff_apply_leave , creating new file\n");}

    while (fgets(line1, sizeof(line1), file) != NULL){
        sscanf(line1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                id,password, name,gender,school,department,leave_type,
                startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);


        if (strcmp(input_id,id)==0){

            if (strcmp(leave_status,"APPROVED")==0){

                printf("\nNO.%d\n",no);
                printf("START DAY    : %s/%s/%s\n",startDay, startMonth, startYear);
                printf("END DAY      : %s/%s/%s\n",endDay, endMonth, endYear);
                printf("LEAVE TYPE   : %s\n",leave_type);
                printf("TOTAL DAYS   : %s\n",totalDays);
                printf("LEAVE REASON : %s\n",leave_reason);
                printf("LEAVE STATUS : %s\n",leave_status);
                found=false;
                no++;
            }
        }
    }
    if (found)
        printf("NONE\n");

    printf("\n\n----------------------------------------   Leave Balance  ----------------------------------------------\n\n");



    FILE *file_2 = fopen(id_txt, "r");
    if (file_2 == NULL) {
        printf("Not able to open %s, creating new file\n",id_txt);}

    while (fgets(line1, sizeof(line1), file_2) != NULL){
        sscanf(line1, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%d,%d,%d,%d,%d,%[^,],%[^\n]",
               id, password, name, gender,&int_phone_number,email, &annual_leave, &compassionate_leave, &emergency_leave, &medical_leave,
               &maternity_leave,school, department);

       if (strcmp(input_id,id)==0){
            printf("Annual Leave        : %d  Days\n"
                   "Compassionate Leave : %d  Days\n"
                   "Emergency Leave     : %d  Days\n"
                   "Medical Leave       : %d Days\n"
                   "Maternity Leave     : %d Days\n",
                   annual_leave, compassionate_leave, emergency_leave, medical_leave,maternity_leave);
        }
    }

    printf("\n\n----------------------------------------   Pending Leave  ----------------------------------------------\n\n");

    found=true;
    no=1;

    FILE *file_3 = fopen("staff_apply_leave.txt", "r");
    if (file_3 == NULL) {
        printf("Not able to open staff_apply_leave , creating new file\n");}

    while (fgets(line1,sizeof(line1), file_3) != NULL){
        sscanf(line1, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                id,password, name,gender,school,department,leave_type,
                startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);

        if (strcmp(input_id,id)==0){

            if (strcmp(leave_status,"IN APPLICATION")==0){
                printf("\nNO.%d\n",no);
                printf("START DAY    : %s/%s/%s\n",startDay, startMonth, startYear);
                printf("END DAY      : %s/%s/%s\n",endDay, endMonth, endYear);
                printf("LEAVE TYPE   : %s\n",leave_type);
                printf("TOTAL DAYS   : %s\n",totalDays);
                printf("LEAVE REASON : %s\n",leave_reason);
                printf("LEAVE STATUS : %s\n",leave_status);
                found=false;
                no++;
            }
        }
    }
    if (found)
        printf("NONE\n");

    fclose(file);
    fclose(file_2);
    fclose(file_3);
    fclose(file_4);
}

void cancel_leave(){
    bool found=true;
    char id[20];
    char password[20];
    char name[50];
    char gender[10];
    char school[1000];
    char department[1000];
    char leave_type[10000];
    char leave_reason[10000];
    char leave_status[1000];
    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
    int totalDays;
    char line[20000];

    FILE *file = fopen("staff_apply_leave.txt", "r ");
    if (file == NULL) {
        printf("Not able to open staff_apply_leave.txt.\n");
        }

    FILE * fp_tmp = fopen("tmp.txt", "a");
        if (fp_tmp == NULL){
            fp_tmp = fopen("tmp.txt", "w"); }

    while (fgets(line, 20000, file) != NULL){
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%d,%[^,],%[^\n]",
            id,password, name,gender,school,department,leave_type,
            &startDay, &startMonth, &startYear,&endDay, &endMonth, &endYear,&totalDays,leave_reason,leave_status);

        if (strcmp(id,login_id)==0){
            //get/count current time
            int day, month, year;
            int current_day=0;
            current_date(&day, &month, &year);
            month++;
            year=year+1900;
            current_day=year*10000+month*100+day;

            //count staff apply leave start day
            int start_day=0;
            start_day=startYear*10000+startMonth*100+startDay;

            if (start_day>current_day){
                char cancel_choice[10];
                found=false;
                printf("\n\n-------------------------------------------------------------------------------------------------\n\n");
                printf("ID              : %s\n",id);
                printf("Name            : %s\n",name);
                printf("Gender          : %s\n",gender);
                printf("School          : %s\n",school);
                printf("Department      : %s\n",department);
                printf("Leave Type      : %s\n",leave_type);
                printf("Leave Start Day : %d/%d/%d\n",startDay, startMonth, startYear);
                printf("Leave End Day   : %d/%d/%d\n",endDay, endMonth, endYear);
                printf("Total Leave Day : %d\n",totalDays);
                printf("Leave Reason    : %s\n",leave_reason);
                printf("Leave Status    : %s\n",leave_status);
                printf("\n\n-------------------------------------------------------------------------------------------------\n\n");

                bool x=true;
                while(x){
                    printf("\nIs this the leave you want to cancel ? \nEnter (yes/no):");
                    scanf("%s",cancel_choice);

                    if (strcmp(cancel_choice,"yes")==0){

                        //add leave day to staff info file
                        char id_1[10];
                        char password_1[10];
                        char name_1[50];
                        char gender_1[10];
                        int int_phone_number;
                        char email[50];
                        int annual_leave;
                        int compassionate_leave;
                        int emergency_leave;
                        int medical_leave;
                        int maternity_leave;
                        char school_1[1000];
                        char department_1[1000];
                        char line1[20000];
                        char id_txt[100];

                        strcat(id_txt,login_id);
                        strcat(id_txt,".txt");

                        FILE *file_tmp1 = fopen("tmp1.txt", "w");

                        FILE *file_1 = fopen(id_txt, "r");
                        if (file_1 == NULL) {
                            printf("Not able to open %s, creating new file\n",id_txt);
                            break;}

                        while (fgets(line1, 20000, file_1) != NULL){
                            sscanf(line1, "%[^,],%[^,],%[^,],%[^,],%d,%[^,],%d,%d,%d,%d,%d,%[^,],%[^\n]",
                                   id_1, password_1, name_1, gender_1,&int_phone_number,email, &annual_leave,
                                   &compassionate_leave, &emergency_leave, &medical_leave,
                                   &maternity_leave,school_1, department_1);

                            if ((strcmp(leave_type,"Annual Leave")==0) && (strcmp(leave_status,"APPROVE")==0)){
                                annual_leave=annual_leave+totalDays; }
                            else if ((strcmp(leave_type,"Compassionate Leave")==0)&& (strcmp(leave_status,"APPROVE")==0)){
                                compassionate_leave=compassionate_leave+totalDays; }
                            else if ((strcmp(leave_type,"Emergency Leave")==0)&& (strcmp(leave_status,"APPROVE")==0)){
                                emergency_leave=emergency_leave+totalDays; }
                            else if ((strcmp(leave_type,"Medical Leave")==0)&& (strcmp(leave_status,"APPROVE")==0)){
                                medical_leave=medical_leave+totalDays; }
                            else if ((strcmp(leave_type,"Maternity Leave")==0)&& (strcmp(leave_status,"APPROVE")==0)){
                                maternity_leave=maternity_leave+totalDays; }

                            fprintf(file_tmp1, "%s,%s,%s,%s,%d,%s,%d,%d,%d,%d,%d,%s,%s\n",
                                    id_1,password_1, name_1,gender_1,int_phone_number,email,annual_leave,compassionate_leave,
                                    emergency_leave,medical_leave,maternity_leave,school_1,department_1);
                        }
                        printf("\nCancel Successful ^-^ \n");
                        fclose(file_1);
                        fclose(file_tmp1);
                        remove(id_txt);
                        rename("tmp1.txt",id_txt);
                        break;
                    }// yes loop

                    else if (strcmp(cancel_choice,"no")==0){
                        fprintf(fp_tmp, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s\n",
                                id,password, name,gender,school,department,leave_type,
                                startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);
                        break; }
                    else
                        printf("\nPlease enter yes or no.\n");
                }
            }//if (startDay>current_day)
            else
                fprintf(fp_tmp, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s\n",
                        id,password, name,gender,school,department,leave_type,
                        startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);
        } //if (strcmp(id,login_id)==0)
        else{
            fprintf(fp_tmp, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%d,%s,%s\n",
                    id,password, name,gender,school,department,leave_type,
                    startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);
        }
    }// while open staff leave apply file
    if (found)
        printf("You don't have any leave apply. / Cannot cancel the leave before today.");

    fclose(file);
    fclose(fp_tmp);
    remove("staff_apply_leave.txt");
    rename("tmp.txt","staff_apply_leave.txt");
}

void mon_report(){
    int mon_choice;
    int school_choice;
    int month;
    int year;
    bool x=true,found= false;

    char id[20];
    char password[20];
    char name[50];
    char gender[10];
    char school[1000];
    char department[1000];
    char leave_type[10000];
    char leave_reason[10000];
    char leave_status[1000];
    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
    char totalDays[10];
    char line[20000];
    char mon_report_txt[10000];
    char year_txt[100];

    printf("\n\n-----------------------------------------   Monthly Report   -------------------------------------------------\n\n");

    while(x){
        printf("\nView Monthly report, search by:");
        printf("\n1. Month/Year");
        printf("\n2. Month (All Years)");
        printf("\nEnter a number: ");
        scanf("%d",&mon_choice);
        if (mon_choice==1 || mon_choice==2)
            break;
        else
            printf("\nInvalid Number.\n");
    }

    while(x){
        printf("\nSelect a School's monthly report");
        printf("\n1. School of Computer Science");
        printf("\n2. School of Business");
        printf("\nEnter a number: ");
        scanf("%d",&school_choice);
        if (school_choice==1 || school_choice==2)
            break;
        else
            printf("\nInvalid Number.\n");
    }

    switch(mon_choice){
    case 1:
        while(x){
            printf("\nEnter Month/Year (MM/YY):");
            scanf("%d/%d",&month,&year);
            if (month>=1 && month<=12 && year>1990 && year<=2028)
                break;
            else{
                printf("\nInvalid month/year.\n");
                }
        }
        if (month==1)
            strcpy(mon_report_txt, "January");
        else if (month==2){
            strcpy(mon_report_txt, "Febuary");}
        else if (month==3)
            strcpy(mon_report_txt, "March");
        else if (month==4)
            strcpy(mon_report_txt, "April");
        else if (month==5)
            strcpy(mon_report_txt, "May");
        else if (month==6)
            strcpy(mon_report_txt, "June");
        else if (month==7)
            strcpy(mon_report_txt, "July");
        else if (month==8)
            strcpy(mon_report_txt, "August");
        else if (month==9)
            strcpy(mon_report_txt, "September");
        else if (month==10)
            strcpy(mon_report_txt, "October");
        else if (month==11)
            strcpy(mon_report_txt, "November");
        else if (month==12)
            strcpy(mon_report_txt, "December");

        sprintf(year_txt, "%d", year);
        strcat(mon_report_txt,year_txt);
        if (school_choice==1)
            strcat(mon_report_txt,"_CS_MON_RPT.txt");
        else if (school_choice==2)
            strcat(mon_report_txt,"_BUISNESS_MON_RPT.txt");
        remove(mon_report_txt);

        FILE *file = fopen("staff_apply_leave.txt", "r ");
        if (file == NULL) {
            printf("Not able to open staff_apply_leave.txt.\n");}

        int no=0;
        //design
        if (school_choice==1)
            printf("\n\n------------------------------------------- School of Computer Science Monthly Report   -----------------------------------------------------\n");
        else if (school_choice==2)
            printf("\n\n------------------------------------------- School of School of Business Monthly Report   -----------------------------------------------------\n");
        printf("\n\n______________________________________________________________________________________________________________________________________________________\n\n");
        printf("NO.        DEPARTMENT                                   STAFF ID          NAME         LEAVE TYPE              APPLY TOTAL DAYS         LEAVE STATUS    ");
        printf("\n______________________________________________________________________________________________________________________________________________________\n\n");

        int loop=0;
        while (fgets(line, 20000, file) != NULL){
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%[^,],%[^,],%[^\n]",
                    id,password, name,gender,school,department,leave_type,
                    &startDay, &startMonth, &startYear,&endDay, &endMonth, &endYear,totalDays,leave_reason,leave_status);

            int count_id=45-strlen(department)+5-1;
            int count_dep=11-2+strlen(department);
            int count_name=18-5+strlen(name)-1;
            int count_type=13-strlen(name)+strlen(leave_type)-1;
            int count_total_day=24-strlen(leave_type)+strlen(totalDays)-1;
            int count_status=25-strlen(totalDays)+strlen(leave_status)-1;

            if (school_choice==1 && month==startMonth && year==startYear && (strcmp(school,"School of Computer Science")==0)) {
                no++;
                loop++;
                printf("%d %*s %*s %*s %*s %*s %*s\n",
                        no,count_dep,department, count_id, id,count_name, name,count_type, leave_type, count_total_day,
                        totalDays,count_status,leave_status);

                FILE * file_mon = fopen(mon_report_txt, "a");
                if(file_mon == NULL){
                    file_mon = fopen(mon_report_txt, "w");
                    exit(0);
                    //The exit(0) function call in the code you provided will immediately terminate the program's execution with a status code of 0.
                    //In this specific case, the exit(0) function call is being used inside an if statement that checks
                    //whether the fopen() function was successful in opening a file called mon_report_txt for appending.
                }
                fprintf(file_mon, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%s,%s,%s\n",
                        id,password, name,gender,school,department,leave_type,
                        startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);
                fclose(file_mon);
            }

            else if (school_choice==2 && month==startMonth && year==startYear && (strcmp(school,"School of Business")==0)) {
                loop++;
                no++;
                printf("%d %*s %*s %*s %*s %*s %*s\n",
                        no,count_dep,department, count_id, id,count_name, name,count_type, leave_type, count_total_day,
                        totalDays,count_status,leave_status);

                FILE * file_mon1 = fopen(mon_report_txt, "a");
                if(file_mon1 == NULL){
                    file_mon1 = fopen(mon_report_txt, "w");
                    exit(0);
                }
                fprintf(file_mon1, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%s,%s,%s\n",
                        id,password, name,gender,school,department,leave_type,
                        startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);
                fclose(file_mon1);
            }
        } // while
        if (loop==0)
            printf("\nThis month/year No employee has applied for leave.\n");
        fclose(file);
        break;

    case 2:
        while(x){
            printf("\nEnter Month:");
            scanf("%d",&month);
            if (month>=1 && month<=12)
                break;
            else
                printf("\nInvalid month.");
        }
        if (month==1)
            strcpy(mon_report_txt, "January");
        else if (month==2)
            strcpy(mon_report_txt, "Febuary");
        else if (month==3)
            strcpy(mon_report_txt, "March");
        else if (month==4)
            strcpy(mon_report_txt, "April");
        else if (month==5)
            strcpy(mon_report_txt, "May");
        else if (month==6)
            strcpy(mon_report_txt, "June");
        else if (month==7)
            strcpy(mon_report_txt, "July");
        else if (month==8)
            strcpy(mon_report_txt, "August");
        else if (month==9)
            strcpy(mon_report_txt, "September");
        else if (month==10)
            strcpy(mon_report_txt, "October");
        else if (month==11)
            strcpy(mon_report_txt, "November");
        else if (month==12)
            strcpy(mon_report_txt, "December");

        if (school_choice==1)
            strcat(mon_report_txt,"_CS_MON_RPT.txt");
        else if (school_choice==2)
            strcat(mon_report_txt,"_BUISNESS_MON_RPT.txt");
        remove(mon_report_txt);

        FILE *file1 = fopen("staff_apply_leave.txt", "r ");
        if (file1 == NULL) {
            printf("Not able to open staff_apply_leave.txt.\n");}

        no=0;
        if (school_choice==1)
            printf("\n\n------------------------------------------- School of Computer Science Monthly Report   -----------------------------------------------------\n");
        else if (school_choice==2)
            printf("\n\n------------------------------------------- School of School of Business Monthly Report   -----------------------------------------------------\n");
        printf("\n\n______________________________________________________________________________________________________________________________________________________\n\n");
        printf("NO.        DEPARTMENT                                   STAFF ID          NAME         LEAVE TYPE              APPLY TOTAL DAYS         LEAVE STATUS    ");
        printf("\n______________________________________________________________________________________________________________________________________________________\n\n");

        loop=0;
        while (fgets(line, 20000, file1) != NULL){
            sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d,%[^,],%[^,],%[^\n]",
                    id,password, name,gender,school,department,leave_type,
                    &startDay, &startMonth, &startYear,&endDay, &endMonth, &endYear,totalDays,leave_reason,leave_status);
            int count_id=45-strlen(department)+5-1;
            int count_dep=11-2+strlen(department);
            int count_name=18-5+strlen(name)-1;
            int count_type=13-strlen(name)+strlen(leave_type)-1;
            int count_total_day=24-strlen(leave_type)+strlen(totalDays)-1;
            int count_status=25-strlen(totalDays)+strlen(leave_status)-1;

            if (school_choice==1 && month==startMonth && (strcmp(school,"School of Computer Science")==0)) {
                loop++;
                no++;
                printf("%d %*s %*s %*s %*s %*s %*s\n",
                        no,count_dep,department, count_id, id,count_name, name,count_type, leave_type, count_total_day,totalDays,
                        count_status,leave_status);

                FILE * file_mon = fopen(mon_report_txt, "a");
                if(file_mon == NULL){
                    file_mon = fopen(mon_report_txt, "w");
                    exit(0);
                }
                fprintf(file_mon, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%s,%s,%s\n",
                        id,password, name,gender,school,department,leave_type,
                        startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);
                fclose(file_mon);
            }

            else if (school_choice==2 && month==startMonth && (strcmp(school,"School of Business")==0)) {
                loop++;
                no++;
                printf("%d %*s %*s %*s %*s %*s %*s\n",
                        no,count_dep,department, count_id, id,count_name, name,count_type, leave_type, count_total_day,
                        totalDays,count_status,leave_status);

                FILE * file_mon1 = fopen(mon_report_txt, "a");
                if(file_mon1 == NULL){
                    file_mon1 = fopen(mon_report_txt, "w");
                    exit(0);
                }
                fprintf(file_mon1, "%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%d,%d,%d,%s,%s,%s\n",
                        id,password, name,gender,school,department,leave_type,
                        startDay, startMonth, startYear,endDay, endMonth, endYear,totalDays,leave_reason,leave_status);
                fclose(file_mon1);
            }
        }
        if (loop==0)
            printf("This month for all year No employee has applied for leave.\n");
        fclose(file1);
        break;

    } //switch
}

int main(void) {
    bool x=true,found=true,found_1=false;

    while (x){
        printf("\n--------------------------------------   Welcome to APU website   ----------------------------------\n");
        get_login_info();
        if (check_role("admin_id.txt")) {
            printf("Login successful!\n");
            while (x){
                found_1=false;
                int choice_admin;
                printf("\n\n-----------------------------------------   ADMIN PAGE   ----------------------------------------\n\n");
                printf("\n1.Add Staff's Information\n");
                printf("2.Update Leave Balance\n");
                printf("3.Search Staff's leave Information\n");
                printf("4.Leave Monthly Report\n");
                printf("5.Exits Admin Page\n");
                printf("\nEnter a Number: ");
                scanf("%d",&choice_admin);
                switch(choice_admin){
                case 1:
                    add_staff_information();
                    break;
                case 2:
                    update_leave_balance();
                    break;
                case 3:
                    admin_check_leave_information();
                    break;
                case 4:
                    mon_report();
                    break;
                case 5:
                    found_1=true;
                    break;
                default:
                    printf("\nInvalid Number.");
                }
                if (found_1)
                    break;
            }
        }

        else if (check_role("staff_id.txt") && check_role("leave_approver_id.txt")) {
            int choice_both;
            x=true;
            while (x){
                printf("\nChoose one role:");
                printf("\n1.Staff");
                printf("\n2.Leave Approver");
                printf("\nEnter a Number: ");
                scanf("%d",&choice_both);
                if (choice_both==1 || choice_both==2)
                    break;
                else
                    printf("\nInvlalid number.\n");
            }

            if (choice_both==1){
                while (x){
                    found_1=false;
                    int choice_staff_1;
                    printf("\n\n-----------------------------------------------   STAFF PAGE   ----------------------------------\n\n");
                    printf("1.Apply Leave\n");
                    printf("2.Cancel Leave\n");
                    printf("3.Check Leave Status\n");
                    printf("4.Check Leave Information\n");
                    printf("5.Exits Staff Page\n");
                    printf("\nEnter a Number: ");
                    scanf("%d",&choice_staff_1);
                    switch(choice_staff_1){
                    case 1:
                        apply_leave();
                        break;
                    case 2:
                        cancel_leave();
                        break;
                    case 3:
                        staff_check_leave_status();
                        break;
                    case 4:
                        staff_check_leave_information();
                        break;
                    case 5:
                        found_1=true;
                        break;
                    default:
                        printf("\nInvalid Number.");
                    }
                    if (found_1)
                        break;
                }
            }
            else if (choice_both==2){
                while (x){
                    found_1=false;
                    int choice_approver_1;

                    printf("\n\n--------------------------------------   LEAVE APPROVE PAGE   ------------------------------------\n\n");
                    printf("1.Approve/Reject Leave\n");
                    printf("2.Search a Date to find total of number of leave\n");
                    printf("3.Exits Leave Approve Page\n");
                    printf("\nEnter a Number: ");
                    scanf("%d",&choice_approver_1);

                    switch(choice_approver_1){
                    case 1:
                        leave_approve();
                        break;
                    case 2:
                        search_date();
                        break;
                    case 3:
                        found_1=true;
                        break;
                    default:
                        printf("\nInvalid Number.");
                    }
                    if (found_1)
                        break;
                }
            }
        }
        else if (check_role("staff_id.txt")) {
            printf("Login successful!\n");
            while (x){
                found_1=false;
                int choice_staff;

                printf("\n\n-----------------------------------------------   STAFF PAGE   ----------------------------------\n\n");
                printf("1.Apply Leave\n");
                printf("2.Cancel Leave\n");
                printf("3.Check Leave Status\n");
                printf("4.Check Leave Information\n");
                printf("5.Exits Staff Page\n");
                printf("\nEnter a Number: ");
                scanf("%d",&choice_staff);
                switch(choice_staff){
                case 1:
                    apply_leave();
                    break;
                case 2:
                    cancel_leave();
                    break;
                case 3:
                    staff_check_leave_status();
                    break;
                case 4:
                    staff_check_leave_information();
                    break;
                case 5:
                    found_1=true;
                    break;
                default:
                    printf("\nInvalid Number.");
                }
                if (found_1)
                    break;
            }
        }
        else if (check_role("leave_approver_id.txt")) {
            printf("Login successful!\n");
            while (x){
                found_1=false;
                int choice_approver;

                printf("\n\n--------------------------------------   LEAVE APPROVE PAGE   ------------------------------------\n\n");
                printf("1.Approve/Reject Leave\n");
                printf("2.Search a Date to find total of number of leave\n");
                printf("3.Exits Leave Approve Page\n");
                printf("\nEnter a Number: ");
                scanf("%d",&choice_approver);

                switch(choice_approver){
                case 1:
                    leave_approve();
                    break;
                case 2:
                    search_date();
                    break;
                case 3:
                    found_1=true;
                    break;
                default:
                    printf("\nInvalid Number.");
                }
                if (found_1)
                    break;
            }
        }

        else {
            printf("Invalid ID or Password.\n");}

    }

return 0;}

