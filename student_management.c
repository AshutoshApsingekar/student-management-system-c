#include <stdio.h>
#include <string.h>

int main() {
	int choice;
	int roll[100];
	char name[100][50];
	float marks[100];
	int studcnt = 0;
	int search;
	int found = 0;
	int topper = 0;
	float average = 0;
	float sum;
	float highest, lowest;
	int passcnt = 0, failcnt = 0;
	int count = 0;

	FILE *fp = fopen("Students.txt","r");
	if(fp != NULL)
	{
		while(studcnt < 100 && fscanf(fp, "\n%49s %d \n%f\n", &name[studcnt], &roll[studcnt], &marks[studcnt]) == 3)
		{
			studcnt++;
		}

		fclose(fp);
	}
	else
	{
		printf("\nFile Does Not Exist !!");
	}

	do {
		printf("\n==== STUDENT MANAGEMENT SYSTEM ==== ");
		printf("\n1. Add Student : ");
		printf("\n2. Display Students : ");
		printf("\n3. Search Student : ");
		printf("\n4. Update Student : ");
		printf("\n5. Delete Student : ");
		printf("\n6. Save Student to File : ");
		printf("\n7. Total Students Count : ");
		printf("\n8. Sort Students by Marks & Find Topper : ");
		printf("\n9. Search Student by Name : ");
		printf("\n10. Calculate Average Marks : ");
		printf("\n11. Find Highest and Lowest Marks: ");
		printf("\n12. Display Passed and Failed Students : ");
		printf("\n13. Find Students Above Given Marks : ");
		printf("\n14. Exit : \n");

		scanf("%d", &choice);

		switch (choice) {
		case 1:
			found = 0;
			if(studcnt >= 100)
			{
				printf("\nStudents Limit Reached !!");
				break;
			}
			printf("Add Student Selected\n");
			printf("Enter Roll No. of the Student : ");
			scanf("%d", &roll[studcnt]);
			for(int i=0; i<studcnt; i++)
			{
				if(roll[studcnt] == roll[i])
				{
					printf("Roll No. Already Exists !!");
					found = 1;
				}
			}
			if(found == 1)
				break;
			printf("Enter Student Name : ");
			scanf("%49s", name[studcnt]);
			found = 0;
			for(int i=0; i<studcnt; i++)
			{
				if(strcmp(name[studcnt], name[i]) == 0)
				{
					printf("Name Already Exists !!");
					found = 1;
				}
			}
			if(found == 1)
				break;
			printf("Enter Marks : ");
			scanf("%f", &marks[studcnt]);
			found = 0;
			if(marks[studcnt]<0 || marks[studcnt]>100)
			{
				printf("\nInvalid Marks Entered !!\n");
				found = 1;
			}
			if(found == 1)
				break;
			else
				printf("Student Added Succsessfully !!\n");
			studcnt++;

			break;

		case 2:
			printf("\nDisplay Students Selected\n");
			printf("\n==== STUDENT DETAILS ====");
			for (int i = 0; i < studcnt; i++) {
				printf("\nStudent %d ", i + 1);
				printf("\nRoll No : %d ", roll[i]);
				printf(" \nName : %s ", name[i]);
				printf("\nMarks : %f \n", marks[i]);
			}
			break;

		case 3:
			found = 0;
			printf("\nSearch Student Selected : ");
			printf("\nEnter Roll No. To Be Searched : ");
			scanf("%d", &search);
			for (int i = 0; i < studcnt; i++) {
				if (search == roll[i]) {
					printf("\nStudent %d ", i + 1);
					printf("\nRoll No : %d ", roll[i]);
					printf(" \nName : %s ", name[i]);
					printf("\nMarks : %f \n", marks[i]);
					found = 1;
					break;
				}
			}
			if (found == 0) {
				printf("\nStudent Not Found\n");
			}
			break;

		case 4:
			found = 0;
			printf("Update Student Selected");
			printf("\nEnter Student's Roll No. To Be Updated : ");
			scanf("%d", &search);
			for (int i = 0; i < studcnt; i++)
			{
				if (search == roll[i])
				{
					printf("Student Found\n");
					printf("Enter Student's Name : ");
					scanf("%s", &name[i]);
					printf("Enter Students's Marks : ");
					scanf("%f", &marks[i]);
					if(marks[i]<0 || marks[i]>100)
					{
						printf("\nInvalid Marks Entered!!\n");
						break;
					}
					else
					{
						found = 1;
						printf("\nStudent Updated Successfully!\n");
					}

				}
			}
			if (found == 0)
			{
				printf("\nStudent Not Found\n");
			}
			break;

		case 5:
			found = 0;
			if(studcnt == 0)
			{
				printf("\nNo Students Available!!");
			}
			else
			{
				printf("Delete Student Selected : ");
				printf("\nEnter Roll No of the Student to be deleted :");
				scanf("%d", &search);
				for (int i = 0; i < studcnt; i++)
				{
					if (search == roll[i])
					{
						for (int j = i; j < studcnt - 1; j++)
						{
							roll[j] = roll[j + 1];
							strcpy(name[j], name[j + 1]);
							marks[j] = marks[j + 1];
						}
						studcnt--;
						found = 1;
						printf("\nStudent Deleted Successfully");
						break;

					}
				}
				if (found == 0) {
					printf("\nStudent Not Found\n");
				}
			}
			break;

		case 6:
			printf("Save Student to File Selected");
			fp = fopen("Students.txt", "w");

			if(fp == NULL)
			{
				printf("\nError Opening File !! ");
				return 1;
			}

			for(int i=0; i<studcnt; i++)
			{
				fprintf(fp,"\n%s %d \n%f\n",name[i],roll[i],marks[i]);
			}

			fclose(fp);
			printf("\nStudents Successfully Saved To File");
			break;

		case 7:
			printf("\nTotal Students : %d\n", studcnt);
			break;

		case 8:
			printf("Sort Students by Marks Selected : ");

			for(int i=0; i<studcnt-1; i++)
			{
				for(int j=0; j<studcnt-i-1; j++)
				{
					if(marks[j]<marks[j+1])
					{
						float temp = marks[j];
						marks[j] = marks[j+1];
						marks[j+1] = temp;

						int temproll = roll[j];
						roll[j] = roll[j+1];
						roll[j+1] = temproll;

						char tempname[50];
						strcpy(tempname, name[j]);
						strcpy(name[j], name[j+1]);
						strcpy(name[j+1], tempname);
					}
				}
			}

			printf("Sorted Students by Marks : ");
			for(int i=0; i<studcnt; i++)
			{
				printf("\nRoll No. : %d", roll[i]);
				printf("\nName : %s", name[i]);
				printf("\nMarks : %f\n", marks[i]);
			}
			printf("\nTop Student's Marks : ");
			if(studcnt>0)
			{
				printf("\n ==== TOPPER ====");
				printf("\nRoll No. : %d", roll[0]);
				printf("\nName : %s", name[0]);
				printf("\nMarks : %f", marks[0]);
			}
			else
			{
				printf("\nNo Students Available!!");
			}
			break;

		case 9:
			found = 0;
			char searchname[50];
			printf("\nSearch Student by Name Selected : ");
			printf("\nEnter the Name of the Student : ");
			scanf("%s", searchname);
			for(int i=0; i<studcnt; i++)
			{
				if(strcmp(searchname, name[i]) == 0)
				{
					printf("\nRoll : %d", roll[i]);
					printf("\nName : %s", name[i]);
					printf("\nMarks : %f", marks[i]);
					found = 1;
					break;
				}
			}
			if(found == 0)
			{
				printf("Student Not Found! ");
			}

			break;

		case 10:
			printf("\nCalculate Average Marks Selected :\n ");
			if( studcnt == 0)
			{
				printf("\nNo Students Available!!");
			}
			else
			{
				sum = 0;

				for(int i=0; i<studcnt; i++)
				{
					sum = sum + marks[i];
				}
				average = sum/studcnt;
				printf("\nAverage Marks : %f\n", average);
			}
			break;

		case 11:
			printf("Find Highest and Lowest Marks Selected : ");
			if(studcnt == 0)
			{
				printf("No Students Available!!");
			}
			else
			{
				for(int i=0; i<studcnt-1; i++)
				{
					for(int j=0; j<studcnt-i-1; j++)
					{
						if(marks[j]<marks[j+1])
						{
							float temp = marks[j];
							marks[j] = marks[j+1];
							marks[j+1] = temp;

							int temproll = roll[j];
							roll[j] = roll[j+1];
							roll[j+1] = temproll;

							char tempname[50];
							strcpy(tempname, name[j]);
							strcpy(name[j], name[j+1]);
							strcpy(name[j+1], tempname);
						}
					}
				}

				printf("\nHighest : %d - %s - %f", roll[0], name[0], marks[0]);
				printf("\nLowest : %d - %s - %f", roll[studcnt-1], name[studcnt-1], marks[studcnt-1]);
			}

			break;

		case 12:
			passcnt = 0;
			failcnt = 0;
			printf("\nDisplay Passed and Failed Students Selected : ");
			if(studcnt == 0)
			{
				printf("\n No Students Available!!");
			}
			else
			{
				printf(" \n=== Passed Students === ");
				for(int i=0; i<studcnt; i++)
				{
					if(marks[i] >= 35)
					{
						printf("\nRoll : %d", roll[i]);
						printf("\nName : %s", name[i]);
						printf("\nMarks : %f\n", marks[i]);
						passcnt++;
					}
				}
				printf(" \n=== Failed Students === ");
				for(int i=0; i<studcnt; i++)
				{
					if(marks[i] < 35)
					{
						printf("\nRoll : %d", roll[i]);
						printf("\nName : %s", name[i]);
						printf("\nMarks : %f\n", marks[i]);
						failcnt++;
					}
				}
			}
			printf("\nTotal Students Passed : %d\n", passcnt);
			printf("\nTotal Students Failed : %d\n", failcnt);
			break;

		case 13:
			int threshold;
			if(studcnt == 0)
			{
				printf("\nNo Students Available!!");
			}
			else
			{
				printf("\nFind Students Above Given Marks Selected : ");
				printf("\nEnter Marks Threshold : ");
				scanf("%d", &threshold);
				printf("\n=== Students Scoring Above %d === \n", threshold);
				for(int i=0; i<studcnt; i++)
				{
					if (marks[i] > threshold)
					{
						printf("\nRoll : %d", roll[i]);
						printf("\nName : %s", name[i]);
						printf("\nMarks : %f\n", marks[i]);
						count++;
					}
				}

				if(count == 0)
				{
					printf("\nNo Students Found!!");
				}
				else
				{
					printf("\nTotal Students Found : %d", count);
				}
			}
			break;

		case 14:
			int minmarks;
			int maxmarks;
			printf("\n=== Students Scoring Between Range Selected ===\n");
			if(studcnt == 0)
			{
				printf("\nNo Students Available!! ");
			}
			else
			{
				printf("\nEnter the Minimum Marks For the Range : ");
				scanf("%d", &minmarks);
				printf("\nEnter the Maximum Marks For the Range : ");
				scanf("%d", &maxmarks);

				for( int i=0; i<studcnt; i++ )
				{
					if( marks[i]>=minmarks && marks[i]<=maxmarks)
					{
						printf("\nRoll : %d", roll[i]);
						printf("\nName : %s", name[i]);
						printf("\nMarks : %f\n", marks[i]);
						count++;
					}
				}
				if(count == 0)
				{
					printf("\nNo Students Found!!");
				}
				else
				{
					printf("\nTotal Students Found : %d", count);
				}
			}
			break;

		case 15:
			printf("Exiting....\n");
			break;

		default:
			printf("Invalid Choice\n");
			break;
		}

	}
	while (choice !=15);

	return 0;
}
