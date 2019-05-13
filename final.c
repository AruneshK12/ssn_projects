/*A-8 Mini Project Batch-1: String Computer*/
/*BY Arunesh Kumar CSE-A 185001024*/

/*Code:-*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int minimum(int a,int b);
void calc_min_steps(char *str1, char *str2,int len1,int len2);
void split(char *input, char *str1,char *str2);
void readfile(char *filename);


void main()
{	printf("\t\t\t\t\t\t------------Welcome to String Computer------------\n");
	printf("\t\t\t\t\t\tThe input file is in the name \" input.txt\" \n");
	printf("\t\t\t\t\t\tThe main program will be executed now....\n");
	FILE *finput,*foutput;  
	char tempin[102];
	int counter=0;
	finput = fopen("input.txt","r");
	if(finput==NULL)
		{printf("\t\t\t\t\t\tInput File dosent exist\n");
		exit(0);
		}		
	foutput = fopen("output.txt","w");
	fscanf(finput," %[^\n]",tempin);
 	char str1[100],str2[100];
	while(strcmp(tempin,"#"))
	{	
		split(tempin,str1,str2);
		int str1len,str2len;
		str1len=strlen(str1);
		str2len=strlen(str2);
		calc_min_steps(str1,str2,str1len,str2len);
		counter=counter+1;
		fscanf(finput," %[^\n]",tempin);
	}
	fclose(finput);
	fclose(foutput);
	printf("\t\t\t\t\t\t------The total number of strings converted==>%d\n",counter);
	printf("\t\t\t\t\t\tWould u like to read the input file(y or n): ");
	char option;
	char *inputname="input.txt",*outputname="output.txt";
	scanf(" %c",&option);
	printf("\n");
	if(option=='y')
		{readfile(inputname);}
	printf("\n\t\t\t\t\t\tWould u like to read the output file(y or n): ");
	scanf(" %c",&option);
	printf("\n");
	if(option=='y')
		{readfile(outputname);}
	printf("\n\t\t\t\t\t\t---------------THE PROGRAM WILL END---------------\n");

	return;
			
}


void readfile(char *filename)
{	FILE *fptr;
	fptr=fopen(filename,"r");
	if(fptr==NULL)
	{
		printf("File dosen't exist\n");
	}
	else
	{
		printf("\t\t\t\t\t\tThe text present in the file is:-\n");
		char c;
		printf("\t\t\t\t\t\t\t");
		while((c=getc(fptr))!=EOF)
		{	
			printf("%c",c);
			if(c=='\n'){printf("\t\t\t\t\t\t\t");}
		}
	}
	fclose(fptr);
	return;
}

int minimum(int a, int b)
{
	int temp=a;
	if(b<a)
	{temp=b;}
	return temp;
}

void calc_min_steps(char *str1, char *str2,int len1,int len2)
{  
	int Sol[len1+ 1][len2 + 1];
    	Sol[0][0] = 0;
	for (int s1 = 1; s1 <= len1; s1++)
		{Sol[s1][0] = s1;}/*the base case where the output is empty string so deleting all letters*/

	for (int s2 = 1; s2 <= len2; s2++)
		{Sol[0][s2] = s2;}/*the base case where the input is empty string so inserting all letters onto new string*/

	for (int s1 = 1; s1 <= len1; s1++)
	{
		for (int s2 = 1; s2 <= len2; s2++)
		{
			if (str1[s1 - 1] == str2[s2 - 1])				
				{ Sol[s1][s2]=Sol[s1-1][s2-1]; }
			else
	
			{ Sol[s1][s2] = 1+ minimum( minimum( Sol[s1 - 1][s2], Sol[s1][s2 - 1] ),  Sol[s1 - 1][s2 - 1] ); }
			/*
			here i=string1 length j=string2 length
			Solutions[i-1][j]==the step where a letter is deleted from string1 so remaining characters would be i-1
			Solutions[i][j-1]==the step where a letter is added to string 1 do remaining characters to check would be j-1 in string2
			Solutions[i-1][j-1]==the step where a letter is replaced in string 1 from string 2 so remaining characters would be i-1 and j-1 in both strings.
			*/
		}
	}
	/*--------For Dyanmic Programming purpose-----*/

/*for(int i=0;i<=len1;i++)
	{	
		for(int j=0;j<len2;j++)
		{
			printf("%d ",Sol[i][j]);
		}
		printf("\n");	
	}
*/

/*-------------------printing of data-------------*/
	  int s1 = len1, s2 = len2;
	  FILE *foperation;
	  foperation=fopen("output.txt","a");
 	 while(s1 > 0 || s2 > 0)
  	{ 
    if (s2==0)/*this refers to the case where there are 0 characters in the converted string*/
    {
      fprintf(foperation,"D%c%02d",str1[s1-1],s1);
      s1=s1-1;
    }

    else if(s1==0)/*this refers to the case where there are 0 characters in the initial string*/
    {
      fprintf(foperation,"I%c%02d",str2[s2-1],s1+1);
      s2=s2-1;
    }

    else if (Sol[s1-1][s2-1] <= Sol[s1][s2-1] && Sol[s1-1][s2-1] <= Sol[s1-1][s2])/*this case is to check wether the number of steps in replacing less than both inserting and deleteing the characters*/
    {
      if(Sol[s1][s2] != Sol[s1-1][s2-1])
      {
          fprintf(foperation,"C%c%02d",str2[s2-1],s1);
      }
      s1=s1-1;
      s2=s2-1;
    }
    else if (Sol[s1][s2-1] < Sol[s1-1][s2])/*this case is to check wether inserting step will have least steps*/
    {
      fprintf(foperation,"I%c%02d",str2[s2-1],s1+1);
      s2=s2-1;
    } 
    else/*the last case where the deletion is the final step possible if all test cases fail*/
    {
      fprintf(foperation,"D%c%02d",str1[s1-1],s1);

      s1=s1-1;
    }
  }

  fprintf(foperation,"E\n");
  fclose(foperation);
return;
}


void split(char *input, char *str1,char *str2)
{

  int countstr1 = 0, countstr2 = 0;
  while(input[countstr1] != ' ')
  {
    str1[countstr1] = input[countstr1];
    countstr1+=1;;
  }

  str1[countstr1] = '\0';
  countstr1=countstr1+1;

  while(countstr1<=strlen(input))
  {
    str2[countstr2] = input[countstr1];
    countstr1+=1;
    countstr2+=1;
  }

  str2[countstr2] = '\0';
  return;
}
/*Output:-
						------------Welcome to String Computer------------
						The input file is in the name " input.txt" 
						The main program will be executed now....
						------The total number of strings converted==>48
						Would u like to read the input file(y or n): y

						The text present in the file is:-
							abcde bcgfe
							abcdefg abcdefg
							abcdef abccdef
							abccdef abcdef
							aabbcc adbc
							adbc aabbcc
							ab abcd
							abcd ab
							a bcd
							b bcd
							b dbc
							b cdb
							bcd b
							cbd b
							cdb b
							cdb a
							abc zbc
							bac bzc
							acb acz
							cab crab
							cab cob
							crab cab
							abcd xbcdzyxabcd
							xbcdzyxabcd abcd
							xbcdzyxakbkckdk abcd
							abcd xbcdzyxakbkckdk
							xbcdzyxakbkckdk abcld
							abcld xbcdzyxakbkckdk
							abcxdefxghixxjklxxmn abcyydefyyghiyjklymn
							abcdefghijklmnopqrst tsrqponmlkjihgfedcba
							abababababababababab abababababababababab
							aaaaaaaaaaaaaaaaaaaa aaaaaaaaaaaaaaaaaaaa
							abab azaz
							ababab azazaz
							abababab azazazaz
							ababababab azazazazaz
							abcabc acbacb
							abcabcabc acbacb
							acbacb abcabcabc
							abcabcabc acbacbacb
							abcdabcdabcdabcdabcd dbcadbcadbcadbcadbca
							abcdabcdabcdabcdabcd dcbadcbadcbadcbadcba
							abababababababababab azazazazazazazazazaz
							abcabcabcabcabcabcab acbacbacbacbacbacbac
							ashdfkh saxugjsdfkjg
							ljhlkhaskdf lkshljhsalkdh
							iuryiuywroiuyr oiewoiwyeiyiu
							ljhlkjhhjhjhjl ljhhkjhkhljhjl
							#
							
						Would u like to read the output file(y or n): y

						The text present in the file is:-
							Cf04Ig04Da01E
							E
							Ic04E
							Dc04E
							Dc06Db04Cd02E
							Ic05Ib04Ca02E
							Id03Ic03E
							Dd04Dc03E
							Cd01Ic01Ib01E
							Id02Ic02E
							Ic02Id01E
							Id01Ic01E
							Dd03Dc02E
							Dd03Dc01E
							Dd02Dc01E
							Ca03Dd02Dc01E
							Cz01E
							Cz02E
							Cz03E
							Ir02E
							Co02E
							Dr02E
							Ix01Iy01Iz01Id01Ic01Ib01Ix01E
							Dx07Dy06Dz05Dd04Dc03Db02Dx01E
							Dk15Dk13Dk11Dk09Dx07Dy06Dz05Dd04Dc03Db02Dx01E
							Ik05Ik04Ik03Ik02Ix01Iy01Iz01Id01Ic01Ib01Ix01E
							Dk15Cl13Dk11Dk09Dx07Dy06Dz05Dd04Dc03Db02Dx01E
							Ik06Ck04Ik03Ik02Ix01Iy01Iz01Id01Ic01Ib01Ix01E
							Cy18Dx17Cy13Dx12Cy08Iy08Cy04Iy04E
							Ca20Cb19Cc18Cd17Ce16Cf15Cg14Ch13Ci12Cj11Ck10Cl09Cm08Cn07Co06Cp05Cq04Cr03Cs02Ct01E
							E
							E
							Cz04Cz02E
							Cz06Cz04Cz02E
							Cz08Cz06Cz04Cz02E
							Cz10Cz08Cz06Cz04Cz02E
							Cb06Cc05Cb03Cc02E
							Cb09Cc08Dc06Da04Db02E
							Cc06Cb05Ic04Ia03Ib02E
							Cb09Cc08Cb06Cc05Cb03Cc02E
							Ca20Cd17Ca16Cd13Ca12Cd09Ca08Cd05Ca04Cd01E
							Ca20Dc19Cc17Ca15Cc13Ca11Cc09Ca07Cc05Ca03Cc01Id01E
							Cz20Cz18Cz16Cz14Cz12Cz10Cz08Cz06Cz04Cz02E
							Cc20Cb18Cc17Cb15Cc14Cb12Cc11Cb09Cc08Cb06Cc05Cb03Cc02E
							Cg07Ij07Cs03Cj02Ig02Iu02Ix02Is01E
							Ch11Cl08Is07Cj05Cs02Ik02E
							Dr14Dy13Cy10Ci09Ce08Cw06Co04Cw03Ce02Io01E
							Cl10Ch09Ck08Ch04E
							
						---------------THE PROGRAM WILL END---------------

*/


