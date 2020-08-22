#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
 
//Function to check Grade of a subject or lab
bool checkGrade(char grade){
    if(grade == 'O' || grade == 'S' || grade == 'A' || grade == 'B' || grade == 'C' || grade == 'D' || grade == 'F')
        return true;
    else
        return false;
}
 
//Function to calculate total GPA for subjects
int calculateSubjectGPA(int subNumber){
    int failSubject = 0;
    float subjectTotal = 0;
    char *subject = (char*)calloc(subNumber,sizeof(char));
    int i=1;
    while(i <= subNumber){
        printf("Subject [%d] : ",i);
        scanf("%s",&subject[i]);
        subject[i] = toupper(subject[i]);
        if(checkGrade(subject[i]))
            i++;
        else{
            while(1){
                printf("\n!!!Warning!!!\nEnter only O, S, A, B, C, D, F\n");
                printf("\nEnter Subject [%d] GPA : ",i);
                scanf("%s",&subject[i]);
                subject[i] = toupper(subject[i]);
                if(checkGrade(subject[i])){
                    i++;
                    break;
                }
            }
        }
    }
     
    //Logic to find failed subjects
    for(i=1; i<=subNumber; i++){
        if(subject[i] == 'F')
            failSubject++;
    }
       
    //logic for SGPA total grades calculation
    for(i=1; i<=subNumber; i++){
        switch(subject[i]){ 
            case 'O': subjectTotal += 10*3; break;
            case 'S': subjectTotal += 9*3;  break;
            case 'A': subjectTotal += 8*3;  break;
            case 'B': subjectTotal += 7*3;  break;
            case 'C': subjectTotal += 6*3;  break;
            case 'D': subjectTotal += 5*3;  break;
            case 'F': subjectTotal += 0*3;  break;
        }
    }
     
    printf("Total subjects passed: %d\n",subNumber - failSubject);
    if(failSubject > 0)
        printf("Total subjects failed : %d\n", failSubject);
    return subjectTotal;
}
 
//Function to calculate total GPA for labs
int calculateLabGPA(int labNumber){
    int failLab = 0;
    float labTotal = 0;
    char *lab = (char*)calloc(labNumber, sizeof(char));
    int i=1;
    while(i <= labNumber){
        printf("Enter Lab [%d] GPA : ",i);
        scanf("%s",&lab[i]);
        lab[i] = toupper(lab[i]);
        if(checkGrade(lab[i]))
            i++;
        else{
            while(1){
                printf("\n!!!Warning!!!\nEnter only O, S, A, B, C, D, F\n");
                printf("\nSubject [%d] : ",i);
                scanf("%s",&lab[i]);
                lab[i] = toupper(lab[i]);
                if(checkGrade(lab[i])){
                    i++;
                    break;
                }
            }
        }
    }
     
    //Logic to find failed subjects
    for(i=1; i<=labNumber; i++){
        if(lab[i] == 'F')
            failLab++;
    }
       
    //logic for SGPA total grades calculation
    for(i=1; i<=labNumber; i++){
        switch(lab[i]){ 
            case 'O': labTotal += 10*2; break;
            case 'S': labTotal += 9*2;  break;
            case 'A': labTotal += 8*2;  break;
            case 'B': labTotal += 7*2;  break;
            case 'C': labTotal += 6*2;  break;
            case 'D': labTotal += 5*2;  break;
            case 'F': labTotal += 0*2;  break;
        }
    }
     
    printf("Total labs passed: %d\n",labNumber - failLab);
    if(failLab > 0)
        printf("Total labs failed : %d\n", failLab);
    return labTotal;
}
 
//Function for calculating SGPA
void calculateSGPA(int subNumber, int labNumber, float subjectTotal, float labTotal){
    float totalCreditsObtained = subjectTotal + labTotal;
    float totalCredits = (subNumber*3) + (labNumber*2);
    float SGPA = totalCreditsObtained / totalCredits;
    //Setting Green color to print statement
    printf("\033[1;32m"); 
    printf("Your SGPA for %d subjects and %d labs is: %.2f", subNumber, labNumber, SGPA);
    printf("\033[0m"); //Resetting color
}
  
void calculateCGPA(int subNumber, int labNumber, float subjectTotal, float labTotal){
    float totalCreditsObtained = subjectTotal + labTotal;
    float totalCredits = (subNumber*3) + (labNumber*2);
    float CGPA = totalCreditsObtained / totalCredits;
    printf("\033[1;32m");
    printf("Your CGPA for %d subjects and %d labs is: %.2f", subNumber, labNumber, CGPA);
    float PERCENTAGE = (CGPA - 0.75) * 10;
    printf("Your Percentage for %d subjects and %d labs is: %.2f",subNumber, labNumber, PERCENTAGE);
    printf("\033[0m");
}
 
void calculatePERCENTAGE(){
    float PERCENTAGE, CGPA;
    printf("Enter total CGPA of all Semesters: ");
    scanf("%f",&CGPA);
    PERCENTAGE = (CGPA - 0.75) * 10;
    printf("\033[1;32m");
    printf("Your Percentage for %.2f CGPA is %.2f ", CGPA, PERCENTAGE);
    printf("\033[0m");
}
 
int main(){
    //Declaration part
    int choice, subNumber, labNumber;
    float subjectTotal, labTotal;
    char optionRecheck;
    //Introduction to program
    printf("\033[1;33m");
    printf("---------------------------------------------------");
    printf("\n|            !!!WELCOME TO THE PROGRAM!!!         |");
    printf("\n---------------------------------------------------");
    printf("\n This program calculates SGPA, CGPA and PERCENTAGE");
    printf("\n  Please enter O, S, A, B, C, D, F Grades only!!\n");
    printf("\033[0m");
    do{
        printf("\nWhat do you want to Calculate?\n1.SGPA\n2.CGPA\n3.PERCENTAGE\n4.Exit");
        printf("\nPlease enter your choice: ");
        scanf("%d",&choice);
        while(1){
            if(choice == 1 || choice == 2 || choice == 3 || choice == 4)
                break;
            else{
                printf("\033[1;31m");
                printf("\nWarning!!! Enter your choice from above list only!");
                printf("\033[0m");
                printf("\nPlease enter your choice: ");
                scanf("%d",&choice);
            }
        }
        switch(choice){
            case 1: printf("\033[1;32m"); 
                    printf("......................................");
                    printf("\nSGPA will be calculated semester wise");
                    printf("\n......................................");
                    printf("\033[0m");
                    while(1){
                        printf("\nEnter total number of subjects: ");
                        scanf("%d",&subNumber);
                        if(subNumber<8){
                            subjectTotal = calculateSubjectGPA(subNumber);
                            break;
                        }
                        else{
                            printf("\033[1;31m");
                            printf("\nWarning!!! Please enter number of subjects in a semester\n");
                            printf("\033[0m");
                        }
                    }
                    while(1){
                        printf("\nEnter total number of labs: ");
                        scanf("%d",&labNumber);
                        if(labNumber<4){
                            labTotal = calculateLabGPA(labNumber);
                            break;
                        }
                        else{
                            printf("\033[1;31m");
                            printf("\nWarning!!! Please enter number of labs in a semester\n");
                            printf("\033[0m");
                        }
                    }
                    calculateSGPA(subNumber, labNumber, subjectTotal, labTotal);
                    break;
            case 2: printf("\033[1;32m");
                    printf(".........................................");
                    printf("\nCGPA will be calculated overall semesters");
                    printf("\n........................................");
                    printf("\033[0m");
                    char ch;
                    printf("\nDo you have semester wise SGPA with you? (Y/N)");
                    scanf("%s",&ch);
                    ch = toupper(ch);
                    if(ch == 'Y'){
                        float totalCGPA = 0;
                        float semSGPA;
                        int semNumber;
                        printf("\nEnter total number of semesters you want to calculate:");
                        scanf("%d",&semNumber);
                        printf("\nEnter SGPA of all %d semesters\n", semNumber);
                        for(int i=1; i<=semNumber; i++){
                            printf("Enter Sem[%d] SGPA: ",i);
                            scanf("%f",&semSGPA);
                            totalCGPA += semSGPA;
                        }
                        printf("\033[1;32m");
                        printf("\nYour CGPA for %d semesters is %.2f", semNumber, totalCGPA/semNumber);
                        printf("\nYour Percentage for %d semesters is %.2f",semNumber, ((totalCGPA/semNumber)-0.75)*10);
                        printf("\033[0m");
                    }
                    else if(ch == 'N'){
                        while(1){
                            printf("\nEnter total number of subjects: ");
                            scanf("%d",&subNumber);
                            if(subNumber<99){
                                subjectTotal = calculateSubjectGPA(subNumber);
                                break;
                            }
                            else{
                                printf("\033[1;31m");
                                printf("\nWarning!!! Please enter total number of subjects\n");
                                printf("\033[0m");
                            }
                        }
                        while(1){
                            printf("\nEnter total number of labs: ");
                            scanf("%d",&labNumber);
                            if(labNumber<25 && labNumber>2){
                                labTotal = calculateLabGPA(labNumber);
                                break;
                            }
                            else{
                                printf("\033[1;31m");
                                printf("\nWarning!!! Please enter total number of labs\n");
                                printf("\033[0m");
                            }
                        }
                        calculateCGPA(subNumber, labNumber, subjectTotal, labTotal);
                    }
                    break;
            case 3: calculatePERCENTAGE();
                    break;
            case 4: exit(0);
        }
        printf("\033[1;33m");
        printf("\n\n---------------------------------------------");
        printf("\n Would you like to check once again? (Y/N): ");
        printf("\n---------------------------------------------");
        printf("\033[0m");
        printf("\nEnter your Option:  ");
        scanf("%s",&optionRecheck);
        optionRecheck = toupper(optionRecheck);
        if(optionRecheck == 'N'){
            printf("\033[1;33m");
            printf("\n==============================================\n");
            printf("                    THANK YOU                    \n\n ");
            printf("\033[0m");
        }
    }while(optionRecheck == 'Y');
    return 0;
}
