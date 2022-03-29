#include<stdio.h>
//string array of all the name of the lakes
static char lakes[6][20] = {"Superior", "Michigan", "Huron", "Erie", "Ontario", "St. Claire"};
/*Finds the averages temperatures of the lakes
*/
void average(double* lake2D[], int day){
    double lakeAverage[6];
    for(int i=0;i<6;i++){
        for(int j=0; j<day; j++){
            lakeAverage[i]+=lake2D[i][j];
        }
    }
    for(int i=0;i<6;i++){
        lakeAverage[i]/=day;
    }
    double totavg = lakeAverage[0]+lakeAverage[1]+lakeAverage[2]+lakeAverage[3]+lakeAverage[4]+lakeAverage[5];
    totavg = totavg/6;
    printf("-------------------------------------\n");
    printf("Lake Temperature Averages\n");
    printf("Lake Superior: %.2lf\n", lakeAverage[0]);
    printf("Michigan: %.2lf\n", lakeAverage[1]);
    printf("Huron: %.2lf\n", lakeAverage[2]);
    printf("Erie: %.2lf\n", lakeAverage[3]);
    printf("Ontario: %.2lf\n", lakeAverage[4]);
    printf("St. Claire: %.2lf\n", lakeAverage[5]);
    printf("Total average: %.2lf\n", totavg);
    printf("-------------------------------------\n");
    
    //finding the highest and lowest temperature average temperature
    double max=0, min=1000;
    int len = sizeof(lakeAverage)/sizeof(lakeAverage[0]);
    //printf("%d\n", len);
    int max_min[2];//array of the lake names with the max and min
    for(int i=0;i<len;i++){
        if(max<lakeAverage[i]){
            max=lakeAverage[i];
            max_min[0]=i;
        }
    }
    for(int i=0;i<len;i++){
        if(min>lakeAverage[i]){
            min=lakeAverage[i];
            max_min[1]=i;
        }
    }
    printf("Lake %s maximum average temperature: %.2lf\n",lakes[max_min[0]], max);
    printf("Lake %s has the minimum average temperature: %.2lf\n",lakes[max_min[1]], min);
    printf("-------------------------------------\n");
    printf("The Lakes that were above the average Temperature:\n");
    for(int i=0;i<len;i++){
       if(totavg<lakeAverage[i]){
           printf("%s\n",lakes[i]);
       } 
    }
    printf("-------------------------------------\n");
    printf("The Lakes that were above the below Temperature:\n");
    for(int i=0;i<len;i++){
       if(totavg>lakeAverage[i]){
           printf("%s\n",lakes[i]);
       } 
    }
}
/*Finds the month based on the day inputted
*/
int month(int day){
    switch(day){
        case 1 ... 31:
            return 1;
            break;
        case 32 ... 60:
            return 2;
            break;
        case 61 ... 91:
            return 3;
            break;
        case 92 ... 121:
            return 4;
            break;
        case 122 ... 152:
            return 5;
            break;
        case 153 ... 182:
            return 6;
            break;
        case 183 ... 213:
            return 7;
            break;
        case 214 ... 244:
            return 8;
            break;
        case 245 ... 274:
            return 9;
            break;
        case 275 ... 305:
            return 10;
            break;
        case 306 ... 335:
            return 11;
            break;
        case 336 ... 366:
            return 12;
            break;
    }
}
/*Finds the day in the month based on the day inputted
Input: int day
day = day - (total days in months passed)
Output: day of the month
*/
int day(int day){
switch(day){
        case 1 ... 31:
            return day;
            break;
        case 32 ... 60:
            day = day - 31;
            return day;
            break;
        case 61 ... 91:
            day = day - 60;
            return day;
            break;
        case 92 ... 121:
            day = day - 91;
            return day;
            break;
        case 122 ... 152:
            day = day - 121;
            return day;
            break;
        case 153 ... 182:
            day = day - 152;
            return day;
            break;
        case 183 ... 213:
            day = day - 182;
            return day;
            break;
        case 214 ... 244:
            day = day - 213;
            return day;
            break;
        case 245 ... 274:
            day = day - 244;
            return day;
            break;
        case 275 ... 305:
            day = day - 274;
            return day;
            break;
        case 306 ... 335:
            day = day - 305;
            return day;
            break;
        case 336 ... 366:
            day = day - 335;
            return day;
            break;
    }
}
/*Coldest Temperature in the lakes
Input: lakeNum[], double days, int lake_name
Output: Dates of the coldest temperatures
*/
void coldestTemp(double lakeNum[], double days, int lake_name){
    double min=1000;
    //finds the coldest temp
    for(int i=0; i<days; i++){
        if(min>lakeNum[i]){
            min=lakeNum[i];
        }
    }
    //counts the number of duplicates
    int count=0;
    for(int i=0; i<days; i++){
        if(min==lakeNum[i]){
            count++;
        }
    }
    //records the duplicated into the cold array
    int cold[count];
    int count2=0;
    for(int i=0; i<days; i++){
        if(min==lakeNum[i]){
            cold[count2]=i+1;
            count2++;
        }
    }
    int month_date[count];
    int day_date[count];
    //sets the date of the coldest temperature
    for(int i=0;i<count;i++){
        month_date[i] = month(cold[i]);
        day_date[i]=day(cold[i]);
    }
    printf("-------------------------------------\n");
    printf("Lake %s\n", lakes[lake_name]);
    printf("Coldest Temp: %.2lf\n", min);
    for(int i=0;i<count;i++){
        printf("%d/%d\n", day_date[i],month_date[i]);
    } 
}
/*Finds the warmest overall temperature of all the lakes
*/
void overall_warmest_temp(double* lake2D[], int numDays){
    printf("-------------------------------------\n");
    double max[6];//max of each lake
    //finding the max of each lake
    for(int i=0;i<6;i++){
        for(int j=0;j<numDays;j++){
            if(max[i]<lake2D[i][j]){
                max[i]=lake2D[i][j];
            }
        }
    }
    double overall_max[2];//[value, lakenumber]
    for(int i=0;i<6;i++){
        if(overall_max[0]<max[i]){
            overall_max[0]=max[i];
            overall_max[1]=i;
        }
    }
    int day_date, month_date;
    //Outputs the dates of the warmest temp with any duplicates
    printf("Lake %s has the warmest overall temperature with a temperature of: %.2lf\n", lakes[(int)overall_max[1]], overall_max[0]);
    for(int i=0;i<numDays;i++){
        if(overall_max[0]==lake2D[(int)overall_max[1]][i]){
            day_date=day(i+1);
            month_date=month(i+1);
            printf("Date: %d/%d\n",day_date,month_date);
        }
    }
}
/*Finds the coldest overall temperature of all the lakes
*/
void overall_coldest_temp(double* lake2D[], int numDays){
    printf("-------------------------------------\n");
    double min[6];//max of each lake
    
    //initializing each index with a value of 100
    for(int i=0;i<6;i++){
        min[i]=100;
    }
    //finding the min of each lake
    for(int i=0;i<6;i++){
        for(int j=0;j<numDays;j++){
            if(min[i]>lake2D[i][j]){
                min[i]=lake2D[i][j];
            }
        }
    }
    double overall_min[2];//[value, lakenumber]
    overall_min[0]=100;
    for(int i=0;i<6;i++){
        if(overall_min[0]>min[i]){
            overall_min[0]=min[i];
            overall_min[1]=i;
        }
    }
    int day_date, month_date;
    //Outputs the dates of the coldest temp with any duplicates
    printf("Lake %s has the coldest overall temperature with a temperature of: %.2lf\n", lakes[(int)overall_min[1]], overall_min[0]);
    printf("Date:\n");
    for(int i=0;i<numDays;i++){
        if(overall_min[0]==lake2D[(int)overall_min[1]][i]){
            day_date=day(i+1);
            month_date=month(i+1);
            printf("%d/%d\n",day_date,month_date);
        }
    }
}
/*Finds the average temperature of the lakes in summer and sorts from greatest to least
*/
void summer_average(double* lake2d[]){
    printf("-------------------------------------\n");
    int summer_start=171;//summer starts on day 172
    int summer_end=265;//summer ends on day 265
    int summer_day=94;//total of days in summer
    double average_temp [6];
    for(int i=0;i<6;i++){
        for(int j=summer_start;j<summer_end;j++){
            average_temp[i]+=lake2d[i][j];
        }
        average_temp[i]=average_temp[i]/summer_day;
    }
    //sorting from warmest temp to coldest temp
    for (int i=0; i<5; i++){ 
       for (int j=0; j<6-i-1; j++){
           if(average_temp[j] < average_temp[j+1]){
              float temp = average_temp[j];
              average_temp[j]=average_temp[j+1];
              average_temp[j+1]=temp;
           }
       }
    }  
    printf("Average Temperatures of the lakes during Summer:\n");
    for(int i=0;i<6;i++){
        printf("Lake %s: %.2fC\n",lakes[i],average_temp[i]);
    }
}
/*Finds the average tempertaure of the lakes in the winter and sorts it from greatest to least
*/
void winter_average(double* lake2d[]){
    printf("-------------------------------------\n");
    int winter_start=0, winter_end=79;//first section of winter
    double average_temp [6];
    //adding up the sum of the temperatures during the first section of winter
    for(int i=0;i<6;i++){
        for(int j=winter_start;j<winter_end;j++){
            average_temp[i]+=lake2d[i][j];
        }
    }
    //adding up the sum of the tempertature during the second section of winter
    int winter2_start=354, winter2_end=365;
    for(int i=0;i<6;i++){
        for(int j=winter2_start;j<winter2_end;j++){
            average_temp[i]+=lake2d[i][j];
        }
    }
    //calculating average of each lake
    int winter_days=90;//total days in winter
    for(int i=0;i<6;i++){
        average_temp[i]=average_temp[i]/winter_days;
    }
    //sorting from warmest temp to coldest temp
    for (int i=0; i<5; i++){ 
       for (int j=0; j<6-i-1; j++){
           if(average_temp[j] < average_temp[j+1]){
              float temp = average_temp[j];
              average_temp[j]=average_temp[j+1];
              average_temp[j+1]=temp;
           }
       }
    }  
    printf("Average Temperatures of the lakes during Winter:\n");
    for(int i=0;i<6;i++){
        printf("Lake %s: %.2fC\n",lakes[i],average_temp[i]);
    }
}
/*Finding number of days where a person is comfortable swimming, when the temperature is above 20 C
*/
void swimming(double* lake2d[], int numDays){
    printf("-------------------------------------\n");
    int total_days[6];//total number of days where people can swim
    for(int i=0;i<6;i++){
        for(int j=0;j<numDays;j++){
            if(lake2d[i][j]>20){
                total_days[i]++;
            }
        }
    }
    printf("Number of days that the lake temperature is above 20 C:\n");
    for(int i=0;i<6;i++){
        printf("Lake %s: %d\n",lakes[i],total_days[i]);
    }
}

void lake_freeze(double* lake2d[], int numDays){
    printf("-------------------------------------\n");
    int total_days[6];
    for(int i=0;i<6;i++){
        for(int j=0;j<numDays;j++){
            if(lake2d[i][j]<0){
                total_days[i]++;
            }
        }
    }
    printf("Number of days that the lake is freezing:\n");
    for(int i=0;i<6;i++){
        printf("Lake %s: %d\n",lakes[i],total_days[i]);
    }
}
int main(void){
    FILE *fp2020 = fopen("2020_waterTemp.txt", "r");
    FILE *rp2020 = fopen("2020_waterTemp.txt", "r");
    int ch2020=0;
    int lines_2020=0;
    while(!feof(rp2020)){
        ch2020 = fgetc(rp2020);
        if(ch2020 == '\n'){
            lines_2020++;
        }
    }
    int year2020[lines_2020], day2020[lines_2020];
    double Superior2020[lines_2020], Michigan2020[lines_2020], Huron2020[lines_2020], Erie2020[lines_2020], Ontario2020[lines_2020], St_Claire2020[lines_2020];
    for(int i=0; i<lines_2020;i++){
        fscanf(fp2020, "%d%d%lf%lf%lf%lf%lf%lf", &year2020[i], &day2020[i], &Superior2020[i], &Michigan2020[i], &Huron2020[i], &Erie2020[i], &Ontario2020[i], &St_Claire2020[i]);
    }
    double* lake2D_2020[6]={Superior2020, Michigan2020, Huron2020, Erie2020, Ontario2020, St_Claire2020};//array of lake arrays (2d array)
    //Question 1 and 2
    average(lake2D_2020, lines_2020);
    
    //Question 3
    coldestTemp(Superior2020, lines_2020, 0);//coldest temp of superior
    coldestTemp(Michigan2020, lines_2020, 1);//coldest temp of michigan
    coldestTemp(Huron2020, lines_2020, 2);//coldest temp of huron
    coldestTemp(Erie2020, lines_2020, 3);//coldest temp of erie
    coldestTemp(Ontario2020, lines_2020, 4);//coldest temp of ontario
    coldestTemp(St_Claire2020, lines_2020, 5);//coldest temp of st. claire
    
    //Question 4
    overall_warmest_temp(lake2D_2020, lines_2020);
    overall_coldest_temp(lake2D_2020,lines_2020);

    //Question 5
    summer_average(lake2D_2020);

    //Question 6
    winter_average(lake2D_2020);

    //Question 7
    swimming(lake2D_2020, lines_2020);

    //Question 8
    lake_freeze(lake2D_2020, lines_2020);

    //Question 9
    FILE *fp2019 = fopen("2019_waterTemp.txt", "r");
    FILE *rp2019 = fopen("2019_waterTemp.txt", "r");
    int ch2019=0;
    int lines_2019=0;
    while(!feof(rp2019)){
        ch2019 = fgetc(rp2019);
        if(ch2019 == '\n'){
            lines_2019++;
        }
    }
    int year2019[lines_2019], day2019[lines_2019];
    double Superior2019[lines_2019], Michigan2019[lines_2019], Huron2019[lines_2019], Erie2019[lines_2019], Ontario2019[lines_2019], St_Claire2019[lines_2019];
    for(int i=0; i<lines_2019;i++){
        fscanf(fp2019, "%d%d%lf%lf%lf%lf%lf%lf", &year2019[i], &day2019[i], &Superior2019[i], &Michigan2019[i], &Huron2019[i], &Erie2019[i], &Ontario2019[i], &St_Claire2019[i]);
    }
    double* lake2D_2019[6]={Superior2019, Michigan2019, Huron2019, Erie2019, Ontario2019, St_Claire2019};//array of lake arrays (2d array)

    average(lake2D_2019, lines_2019);
    
    return 0;
}
