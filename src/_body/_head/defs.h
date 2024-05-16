#define NULL					0



#define ROOT_SIZE				0x20




#define ERR_FTYP				0000
#define ERR_OPEN				0001
#define ERR_LALL				0002
#define ERR_READ				0003
#define ERR_WRTE				0004
#define ERR_SEEK				0005
#define ERR_NFND				0006
#define ERR_CLOS				0007
#define ERR_CDIR				0010
#define ERR_UNKN				0011




/* Macros */
#define PARAM_CLEAR				(data___params & 0b00001)
#define PARAM_VERBO				(data___params & 0b00010)
#define PARAM_DECOP				(data___params & 0b00100)
#define PARAM_OTHER				(00000)
