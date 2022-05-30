  #include <stdio.h>

  int leapYearFeb(int year, int mon) {
        int flag = 0;
        if (year % 100 == 0) {
                if (year % 400 == 0) {
                        if (mon == 2) {
                                flag = 1;
                        }
                }
        } else if (year % 4 == 0) {
                if (mon == 2) {
                        flag = 1;
                }
        }
        return (flag);
  }

  int main() {
    
        int daysInMon[] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
        int days, month, year,daysct,monthct,yearct;
        char dob[100],dob2[100];
        time_t ts;
        struct tm *ct;

        printf("Enter your days of birth:");
        fgets(dob, 100, stdin);
        sscanf(dob, "%d %d %d", &days, &month, &year);
      
        
         printf("Enter Current Date :");
         fgets(dob2, 100, stdin);
        sscanf(dob2, "%d %d %d", &daysct, &monthct, &yearct);
        
        
      
        days = daysInMon[month - 1] - days + 1;

        if (leapYearFeb(year, month)) {
                days = days + 1;
        }

        days = days + daysct;
        month = (12 - month) + (monthct);
        year = (yearct) - year - 1;

        if (leapYearFeb((yearct), (monthct))) {
                if (days >= (daysInMon[monthct] + 1)) {
                        days = days - (daysInMon[monthct] + 1);
                        month = month + 1;
                }
        } 
		
		else if (days >= daysInMon[monthct]) {
                days = days - (daysInMon[monthct]);
                month = month + 1;
        }

        if (month >= 12) {
                year = year + 1;
                month = month - 12;
        }

        printf("Age: %d years %d months and %d days\n", year, month, days);
        return 0;
  }

