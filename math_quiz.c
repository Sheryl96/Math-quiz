#include<stdio.h>
#include<stdlib.h>
int add(int a, int b)
{
	return a*b;
}
int sub(int a, int b)
{
	return a-b;
}
int mult(int a, int b)
{
	return a*b;
}
int divi ( int a, int b)
{
        if ( b != 0 )
                return a/b;
        else
            	return 0;
}
int main()
{
	int quizData[] =  {'+', 6 , 2 ,'-', 9 , 2 ,'*', 3 , 4 ,'*', 2 , 5 ,'/', 8 , 4 ,'+', 3 , 6 ,'-', 4 , 1 ,'*', 3 , 3 ,'/', 5 , 5 ,'-', 8 , 2 };
	FILE *fp ;
	fp = fopen("quiz.out","w+");
	if (fp == NULL)
	{
		printf("Unable to open file");
		exit(EXIT_FAILURE);
	}
	int i, j, temp, res, ans, score=0;
	printf("WELCOME TO MATH QUIZ!\n");
	for (i=30; i<30; i+=3)
	{
		j = rand() % 10;
		j *=3;
		if(i!=j)
		{
			temp = quizData[j];
			quizData[j] = quizData[i];
			quizData[i] = temp;
			
			temp = quizData[j+1];
			quizData[j] = quizData[i+1];
			quizData[i+1] = temp;

			temp = quizData[j+2];
			quizData[j+2] = quizData[i+2];
			quizData[i+2] = temp;
		}
	
	}	
	for(i=0;i<30;i+=3)
	{
		switch (quizData[i])	
		{
			case '+' :   res = add(quizData[i+1],quizData[i+2]);
	                        printf("What is %d plus %d ? \n ", quizData[i+1],  quizData[i+2]);
				fprintf(fp,"What is %d plus %d ? \n", quizData[i+1], quizData[i+2]);
        	                scanf("%d",&ans);
				fprintf(fp,"%d \n",ans);
				if(res==ans)     
                  	        {
                               		 score++;
                                	 printf("Good Job! ");
					 fprintf(fp,"Good Job! ");
                        	}
                        	else
				{
                            		printf("Better luck next time! The answer was %d\n",res);
					fprintf(fp,"Better luck next time! The answer was %d\n", res);
                        	}
				printf("Your score is: %d \n",score);
				fprintf(fp,"Your score is: %d \n",score);
				break;
			case '-' :  res = sub(quizData[i+1],quizData[i+2]);
        	                printf("What is %d minus %d ? \n ", quizData[i+1],  quizData[i+2]);
				fprintf(fp,"What is %d minus %d ? \n", quizData[i+1], quizData[i+2]);
	                        scanf("%d",&ans);
				fprintf(fp,"%d \n",ans);
                	      	if(res==ans)
                       	        {
                               		score++;
                                       	printf("Good Job! ");
				        fprintf(fp,"Good Job! ");
				}
                        	else
				{
                            		printf("Better luck next time! The answer was %d\n",res);
					fprintf(fp,"Better luck next time! The answer was %d\n", res);
				}
				printf("Your score is: %d \n",score);
				fprintf(fp,"Your score is: %d \n",score);
				break;
			case '*' : res = mult(quizData[i+1],quizData[i+2]);
                      	        printf("What is %d times %d ? \n ", quizData[i+1],  quizData[i+2]);
                                fprintf(fp,"What is %d times %d ? \n", quizData[i+1], quizData[i+2]);
				scanf("%d",&ans);
				fprintf(fp,"%d \n",ans);
			        if(res==ans)
                        	{
                                 	score++;
                                	printf("Good Job! ");
					fprintf(fp,"Good Job! ");
				}
                        	else
				{
                            		printf("Better luck next time! The answer was %d\n",res);
					fprintf(fp,"Better luck next time! The answer was %d\n", res);
				}
                        	printf("Your score is: %d \n",score); 
				fprintf(fp,"Your score is: %d \n",score);
				break;
			case '/' : res =divi (quizData[i+1],quizData[i+2]);
	                        printf("What is %d divided by  %d ? \n ", quizData[i+1],  quizData[i+2]);
        	                fprintf(fp,"What is %d divided %d ? \n", quizData[i+1], quizData[i+2]);
				scanf("%d",&ans);
			        fprintf(fp,"%d \n",ans);
				if(res==ans)
                       		{
                               		score++;
                                       	printf("Good Job! ");
					fprintf(fp,"Good Job! ");
			        }
                        	else
				{
                            		printf("Better luck next time! The answer was %d\n",res);
					fprintf(fp,"Better luck next time! The answer was %d\n", res);
                        	}
				printf("Your score is: %d \n",score);
				fprintf(fp,"Your score is: %d \n",score);
				break;
		}
	}
	
	printf("Great! Your quiz is over! Here is the quiz you took! \n\n");
	fclose(fp);	
	int data;
	FILE *fptr = fopen("quiz.out","r");
	while((data=fgetc(fptr))!=EOF)
	{
		printf("%c",data);
	}
	fclose(fptr);
	return (0);
}
