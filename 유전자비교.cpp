#include<stdio.h>
	int dn[101][5001]={0,};
	float same[101][5001]={0.0,};
int main(){
	FILE *ifp=fopen("input.txt","rt"), *ofp=fopen("output.txt","wt");

	int count=0, length=0, i,j,z, mrcheck=0, match=0, comp[3]={0,};
	char sc;
	
	fscanf(ifp,"%d %d", &count, &length);
	for(i=1;i<=count;i++){
		j=0;
		while(j<length){
			j++;
			fscanf(ifp,"%c",&sc);
			if(sc=='a'){
				dn[i][j]=1;
			}else if(sc=='g'){
				dn[i][j]=2;
			}else if(sc=='t'||sc=='u'){
				dn[i][j]=3;
				if(sc=='u'){
					mrcheck=1;
				}
			}else if(sc=='c'){
				dn[i][j]=4;
			}else{
				j--;
			}
		}
	}
	for(i=1;i<=count-1;i++){
		for(j=i+1;j<=count;j++){
			match=0;
			for(z=1;z<=length;z++){
				if(dn[i][z]==dn[j][z]){
					match++;
				}
			}
			same[i][j]=(float)match/length*100;
			same[j][i]=same[i][j];
		}
	}
	for(i=1;i<=count;i++){
		for(j=1;j<=count;j++){
			printf("%.2f%%   ", same[i][j]);
			fprintf(ofp,"%.2f%%   ",same[i][j]);
		}
		printf("\n");
		fprintf(ofp,"\n");
	}

	while(1){
		printf("\nPlease enter Data what you want to compare ( Exit when type 0)\n");
		match=length;
		scanf("%d", &comp[1]);
		if(comp[1]==0){
			break;
		}
		scanf("%d", &comp[2]);
		printf("%d & %d Unmatch : ",comp[1],comp[2]);
		fprintf(ofp,"%d & %d Unmatch : ",comp[1],comp[2]);
		for(z=1;z<=length;z++){
			if(dn[comp[1]][z]!=dn[comp[2]][z]){
				match--;
				printf("%d: ", z);
				fprintf(ofp,"%d: ", z);
				if(dn[comp[1]][z]==1){
					printf("a¡æ");
					fprintf(ofp,"a¡æ");
				}else if(dn[comp[1]][z]==2){
					printf("g¡æ");
					fprintf(ofp,"g¡æ");
				}else if(dn[comp[1]][z]==3){
					if(mrcheck==1){
						printf("u¡æ");
						fprintf(ofp,"u¡æ");
					}else{
						printf("t¡æ");
						fprintf(ofp,"t¡æ");
					}
				}else if(dn[comp[1]][z]==4){
					printf("c¡æ");
					fprintf(ofp,"c¡æ");
				}
				if(dn[comp[2]][z]==1){
					printf("a ");
					fprintf(ofp,"a ");
				}else if(dn[comp[2]][z]==2){
					printf("g ");
					fprintf(ofp,"g ");
				}else if(dn[comp[2]][z]==3){
					if(mrcheck==1){
						printf("u ");
						fprintf(ofp,"u ");
					}else{;
						printf("t ");
						fprintf(ofp,"t ");
					}
				}else if(dn[comp[2]][z]==4){
					printf("c ");
					fprintf(ofp,"c ");
				}
			}
		}
		printf("\nMatch rate : %.2f%\n", (float)match/length*100);
		fprintf(ofp,"\nMatch rate : %.2f%\n", (float)match/length*100);
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}
