#include"add-nbo.h"

#define MAX_VALUE 4294967295

int main(int argc, char* argv[])
{

    char* FileName1 = argv[1];
    char* FileName2 = argv[2];
    uint32_t a1 ;
    uint32_t a2 ;
    uint32_t a3 = 0;
    long long k = 0;

    FILE* fp = fopen(FileName1, "r");
    
    if (fp != NULL)
    {
        fread(&a1, sizeof(uint32_t), 1, fp);
        printf("%x\n",a1);
    }
    fp = fopen(FileName2, "r");
    if (fp != NULL)
    {
        fread(&a2, sizeof(uint32_t), 1, fp);
        printf("%x\n",a2);
    }
    a1=ntohl(a1);
    a2=ntohl(a2);
    
    
    k = (long long)(a1);
    k += (long long)(a2);
    
    if (k > MAX_VALUE)
    {
        a3 = (uint32_t)k+1;
    }
    else
    {
	  a3=a1+a2;
    }
    
    
    
    printf("%u(0x%x) + %u(0x%x)= %u(0x%x)",a1,a1,a2,a2,a3,a3);
    if (fp!=NULL)
	    fclose(fp);
    return 0;
}
