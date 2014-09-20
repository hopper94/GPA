#include <stdio.h>

//function prototype
float gpa(int, int);

struct name{
	char fname[15];//student first name 
	char lname[15];//student last name	
};
struct module{   
	int grade;
    char MID[10];
    int credit;
};
struct student{
	
	int j;
	int grade;
	char sid[8];//student ID
	struct name full;
	struct module data[15];
	int totcred;
};
int main () {	
	
	struct student info[15];
	int i=0, num;
	int students;
	int gcs=0;
	float gpv;//grade point value, grade credit score
	
	
	//FILE *read;
    //read=fopen("assignment_input.txt","r");
	
	//if (read==NULL){
	//printf("File not found!");
	//}
	//else {
	printf("Please enter the number of students: ");
	scanf("%d",&students);
	//fscanf(read,"%d",&students);
	
	for(i=0;i<students;i++){
		
	    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("Student %d:\n",i+1);
	
		printf("\nPlease enter student name: ");
		scanf("%s %s",info[i].full.fname,info[i].full.lname);
		//fscanf(read,"%s %s",info[i].full.fname,info[i].full.lname);
		
		printf("Please enter this students ID: ");
		scanf("%s",info[i].sid);
		//fscanf(read,"%s",info[i].sid);
		
		printf("Enter the number of Modules: ");
		scanf("%d", &info[i].j);
		//fscanf(read,"%d", &info[i].j);
		
	for(num=1;num<=info[i].j;num++){
			
		    printf("\nPlease enter Module %d ID: ",num);
			scanf("%s",info[i].data[num].MID);
			//fscanf(read,"%s",info[i].data[num].MID);
			
			printf("Please enter this modules credit value: ");
			scanf("%d",&info[i].data[num].credit);
			//fscanf(read,"%d",&info[i].data[num].credit);
			
			printf("Please enter students percentage grade: ");
		    scanf("%d",&info[i].data[num].grade);
			//fscanf(read,"%d",&info[i].data[num].grade);
			
		    info[i].totcred=info[i].totcred+info[i].data[num].credit;
		
		}	
	//}
}
	FILE *write;
    write=fopen("assignment_output.txt","w");
    
	printf("\n                  Result                  \n");
	fprintf(write,"\n                  Result                  \n");
	
	for (i=0; i<students; i++){
		
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		fprintf(write,"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		
		printf("Student %d: ",i+1);
		fprintf(write,"Student %d: ",i+1);
		
		printf("\nStudent ID: %s", info[i].sid);
		fprintf(write,"\nStudent ID: %s", info[i].sid);
		
		for (num=1;num<=info[i].j;num++) {
			
			printf("\n\nModule %d ID: %s",num, info[i].data[num].MID);
			fprintf(write,"\n\nModule %d ID: %s",num, info[i].data[num].MID);

			printf("\nModule grade in percentage: %d ",info[i].data[num].grade);
			fprintf(write,"\nModule grade in percentage: %d ",info[i].data[num].grade);

            if (info[i].data[num].grade>=80){
                gpv=4.0;
                printf("\nStudents grade in this module is A");	
				fprintf(write,"\nStudents grade in this module is A");	
            }
			
            if (info[i].data[num].grade>=70 && info[i].data[num].grade<80){
                gpv=3.5;
                printf("\nStudents grade in this module is B+");
				fprintf(write,"\nStudents grade in this module is B+");
            }
			
            if (info[i].data[num].grade>=60 && info[i].data[num].grade<70){
                gpv=3.0;
                printf("\nStudents grade in this module is B");
				fprintf(write,"\nStudents grade in this module is B");
			}
		 
            if (info[i].data[num].grade>=55 && info[i].data[num].grade<60){
                gpv=2.75;
                printf("\nStudents grade in this module is B-");
				fprintf(write,"\nStudents grade in this module is B-");
            }
			
            if (info[i].data[num].grade>=50 && info[i].data[num].grade<55){
                gpv=2.5;
                printf("\nStudents gradein this module is C+");
				fprintf(write,"\nStudents gradein this module is C+");
			}
			
            if (info[i].data[num].grade>=40 && info[i].data[num].grade<50){
                gpv=2.0;
                printf("\nStudents grade in this module is C");
				fprintf(write,"\nStudents grade in this module is C");
            }
			
            if (info[i].data[num].grade>=35 && info[i].data[num].grade<40){
                gpv=1.5;
                fprintf(write,"\nStudents grade in this module is D");    
				printf("\nStudents grade in this module is D");     
            }
            if (info[i].data[num].grade<35){
                gpv=0.0;
                printf("\nStudents grade in this module is F");
				fprintf(write,"\nStudents grade in this module is F");
			}
			gcs=gcs+(gpv * info[i].data[num].credit);

			printf("\n------------------------------------------");
			fprintf(write,"\n------------------------------------------");
		
		}	
		//printf("\n\nTotal credit= %d",info[i].totcred);
		
		printf("\nGPA achieved = %.2f\n",gpa (gcs,info[i].totcred));
		fprintf(write,"\nGPA achieved = %.2f\n",gpa (gcs,info[i].totcred));

		if  (gpa (gcs,info[i].totcred)>=2.00 && gpa (gcs,info[i].totcred)<2.50){
			printf("Pass Qualification\n");
			fprintf(write,"Pass Qualification\n");
        }
        if (gpa (gcs,info[i].totcred)>=2.50 && gpa (gcs,info[i].totcred)<3.00){
            printf("Second class honours, grade 2 Qualification\n ");
			fprintf(write,"Second class honours, grade 2 Qualification\n ");
        }
		if (gpa (gcs,info[i].totcred)>=3.00 &&gpa (gcs,info[i].totcred)<3.25){
            printf("Second class honours, grade 1 Qualification\n ");
			fprintf(write,"Second class honours, grade 1 Qualification\n ");
        }
		if (gpa (gcs,info[i].totcred)>=3.25){
            printf("First class honours Qualification\n");
			fprintf(write,"First class honours Qualification\n");
        }
		else {
			printf("Failed to acheave pass Qualification");
		}

		gcs=0;
	}
    return 0;
}

float gpa (int gcs, int totcred){
	//printf("\nFUNCTION FIRED!!!!!\\n\n");
	//grade credit score devided by total credits for stage
	return (float)gcs/(float)totcred;
}
