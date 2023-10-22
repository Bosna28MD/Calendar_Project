#include <stdio.h>
#include<stdlib.h>

typedef struct data{
    int zi;
    int luna;
    int an;
}Calendar;



int An_Bisect(int an);
int Diferenta_de_Zile(Calendar d1,Calendar d2);
void Data_Calcul(int z1,int l1,int z2,int l2,int an,int *s);
int Nr_Zile_Luna(int luna,int an);
void Lunile(int luna);

void Afisare_Calendar(Calendar d1,Calendar d2);

int main()
{
    Calendar data1,data2;
    
    do{
    printf("Introdu \"Ziua\" de Inceput:");
    scanf("%d",&data1.zi);
    printf("Introdu \"Luna\" de Inceput:");
    scanf("%d",&data1.luna);
    printf("Introdu \"Anul\" de Inceput:");
    scanf("%d",&data1.an);
    printf("\n");
    }while(data1.an<2022);
    
    printf("Introdu \"Ziua\" de Sfarsit:");
    scanf("%d",&data2.zi);
    printf("Introdu \"Luna\" de Sfarsit:");
    scanf("%d",&data2.luna);
    printf("Introdu \"Anul\" de Sfarsit:");
    scanf("%d",&data2.an);
    
    Afisare_Calendar(data1,data2);
    
    
    
   //int t=Nr_Zile_Luna(data1.luna,data1.an);
  // printf("\n\n%d",t);

    return 0;
}





int An_Bisect(int an){
    if(an%400==0 || (an%100!=0 && an%4==0) ) return 1;
    return 0;
}


int Nr_Zile_Luna(int luna,int an){
    int k;
    
 if(luna==1) k=31; 
 else if(luna==2){ 
    if(An_Bisect(an)==1) k=29;
    else { k=28;} 
 }
 else if(luna==3) k=31;
 else if(luna==4) k=30;
 else if(luna==5) k=31;
 else if(luna==6) k=30;
 else if(luna==7) k=31;
 else if(luna==8) k=31;
 else if(luna==9) k=30;
 else if(luna==10) k=31;
 else if(luna==11) k=30;
 else if(luna==12) k=31;
 
 return k;
 
}


void Data_Calcul(int z1,int l1,int z2,int l2,int an,int *s){
    
   if(l1==l2){  *s=*s+(z2-z1+1);  return; }
   int k=Nr_Zile_Luna(l1,an);
   *s=*s+(k-z1+1);
   Data_Calcul(1,l1+1,z2,l2,an,s);
    
}

int Diferenta_de_Zile(Calendar d1,Calendar d2){
    int s=0;
    if(d1.an==d2.an){
        Data_Calcul(d1.zi,d1.luna,d2.zi,d2.luna,d1.an,&s);
    }
    else{
        
     Data_Calcul(d1.zi,d1.luna,31,12,d1.an,&s);
     d1.an++;
     while(d1.an!=d2.an){
        Data_Calcul(1,1,31,12,d1.an,&s); 
        d1.an++; 
     }
     Data_Calcul(1,1,d2.zi,d2.luna,d2.an,&s);
        
    }
    
    return s;
    
}

void Spatii(){
    
    printf("     ");
}

void Spatiu(){
    printf(" ");
}

void Zile_Saptamanii(){
    printf("\n     Luni     Marti     Miercuri     Joi     Vineri     Sambata     Duminica");
}



void Afisare_Calendar(Calendar d1,Calendar d2){
    
    int s=Diferenta_de_Zile(d1,d2);
    //printf("\n\nk=%d",s);
    
    //s=s+pozitia;
    Calendar d3;
    d3.zi=1;
    d3.luna=1;
    d3.an=2022;
    
    int pozitia=Diferenta_de_Zile(d3,d1);
    
    //printf("\n\npozitia:%d",pozitia);
    
    
    pozitia=pozitia+6-1;
    /*
    if(pozitia%7==0){ printf("\nDuminica"); }
    else if(pozitia%7==1){ printf("\nLuni"); }
    else if(pozitia%7==2){ printf("\nMarti"); }
    else if(pozitia%7==3){ printf("\nMiercuri"); }
    else if(pozitia%7==4){ printf("\nJoi"); }
    else if(pozitia%7==5){ printf("\nVineri"); }
    else if(pozitia%7==6){ printf("\nSambata"); }
    */
    Lunile(d1.luna);
    printf("     Luni     Marti     Miercuri     Joi     Vineri     Sambata     Duminica\n");
    /*
    Luni-     5-9
    Marti-    14-19
    Miercuri- 24-32
    Joi-      37-40
    Vineri-   45-51
    Sambata-  56-63
    Duminica- 68-76
    */
    
    
    Calendar d5;
    d5=d1;
    
    if(pozitia%7==0){ int contor=70; while(contor){ printf(" ");  contor--; } printf("%d\n",d5.zi);  } //printf("\nDuminica"); 
    else if(pozitia%7==1){  int contor=6; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);  }//printf("\nLuni"); 
    else if(pozitia%7==2){ int contor=15; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi); }//printf("\nMarti");
    else if(pozitia%7==3){  int contor=26; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);   } //printf("\nMiercuri"); 
    else if(pozitia%7==4){  int contor=38; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);  }//printf("\nJoi"); 
    else if(pozitia%7==5){ int contor=46; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);  }//printf("\nVineri"); 
    else if(pozitia%7==6){ int contor=57; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);  }//printf("\nSambata"); 
    
    s--;
    pozitia++;
    int day_luna=Nr_Zile_Luna(d5.luna,d5.an);
    
    if(d5.zi==day_luna && d5.luna==12){
        d5.zi=1;
        d5.luna=1;
        d5.an++;
        Lunile(d5.luna);
        printf("\n\n     Luni     Marti     Miercuri     Joi     Vineri     Sambata     Duminica\n");
    }
    else if(d5.zi==day_luna){
        d5.zi=1;
        d5.luna++;
        Lunile(d5.luna);
        printf("     Luni     Marti     Miercuri     Joi     Vineri     Sambata     Duminica\n");
    }
    else{
        d5.zi++;
    }
    
    
    
    
    while(s){
        
        if(d5.zi==1){
            
            if(pozitia%7==0){ int contor=70; while(contor){ printf(" ");  contor--; } printf("%d\n",d5.zi);  } //printf("\nDuminica"); 
            else if(pozitia%7==1){  int contor=6; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);  }//printf("\nLuni"); 
            else if(pozitia%7==2){ int contor=15; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi); }//printf("\nMarti");
            else if(pozitia%7==3){  int contor=26; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);   } //printf("\nMiercuri"); 
            else if(pozitia%7==4){  int contor=38; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);  }//printf("\nJoi"); 
            else if(pozitia%7==5){ int contor=46; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);  }//printf("\nVineri"); 
            else if(pozitia%7==6){ int contor=57; while(contor){ printf(" ");  contor--; } printf("%d",d5.zi);  }//printf("\nSambata");
            
            s--;
            pozitia++;
            d5.zi++;
            
            continue;
            
        }
        
        
     if(pozitia%7==0){ int contor; if(d5.zi>=10){ contor=11;  }else{contor=12; } while(contor){ printf(" "); contor--; } printf("%d\n",d5.zi);  }//printf("\nDuminica");  ""
     else if(pozitia%7==1){ int contor; if(d5.zi>=10){ contor=5;  }else{contor=6; } while(contor){ printf(" "); contor--; } printf("%d",d5.zi);   } //printf("\nLuni");  "u"
     else if(pozitia%7==2){ int contor; if(d5.zi>=10){ contor=7;  }else{contor=8; } while(contor){ printf(" "); contor--; } printf("%d",d5.zi);  }//printf("\nMarti");   "a"
     else if(pozitia%7==3){ int contor; if(d5.zi>=10){ contor=9;  }else{contor=10; } while(contor){ printf(" "); contor--; } printf("%d",d5.zi);   }//printf("\nMiercuri"); "e"    
     else if(pozitia%7==4){ int contor; if(d5.zi>=10){ contor=10;  }else{contor=11; } while(contor){ printf(" "); contor--; } printf("%d",d5.zi);  }//printf("\nJoi");      "o"
     else if(pozitia%7==5){ int contor; if(d5.zi>=10){ contor=6;  }else{contor=7; } while(contor){ printf(" "); contor--; } printf("%d",d5.zi); }//printf("\nVineri");     "1-i"
     else if(pozitia%7==6){ int contor; if(d5.zi>=10){ contor=9;  }else{contor=10; } while(contor){ printf(" "); contor--; } printf("%d",d5.zi);  }//printf("\nSambata");   "a"
        
        
        
        
        s--;
        pozitia++;
        
        day_luna=Nr_Zile_Luna(d5.luna,d5.an);
    
    if(d5.zi==day_luna && d5.luna==12){
        d5.zi=1;
        d5.luna=1;
        d5.an++;
        Lunile(d5.luna);
        printf("     Luni     Marti     Miercuri     Joi     Vineri     Sambata     Duminica\n");
    }
    else if(d5.zi==day_luna){
        d5.zi=1;
        d5.luna++;
        Lunile(d5.luna);
        printf("     Luni     Marti     Miercuri     Joi     Vineri     Sambata     Duminica\n");
    }
    else{
        d5.zi++;
    }
        
    }
    
    
    
}


void Lunile(int luna){
    
    if(luna==1){
        printf("\n\n                                        Ianuarie:\n");
    }
    else if(luna==2){
        printf("\n\n                                        Februarie:\n");
    }
    else if(luna==3){
        printf("\n\n                                           Martie:\n ");
    }
    else if(luna==4){
        printf("\n\n                                           Aprilie:\n");
    }
    else if(luna==5){
        printf("\n\n                                               Mai:\n");
    }
    else if(luna==6){
        printf("\n\n                                              Iunie:\n");
    }
    else if(luna==7){
        printf("\n\n                                              Iulie:\n");
    }
    else if(luna==8){
        printf("\n\n                                                August:\n");
    }
    else if(luna==9){
        printf("\n\n                                             Septembrie:\n");
    }
    else if(luna==10){
        printf("\n\n                                              Octombrie:\n");
    }
    else if(luna==11){
        printf("\n\n                                              Noiembrie:\n");
    }
    else if(luna==12){
        printf("\n\n                                              Decembrie:\n");
    }
    
}





