// $Id: misc.h,v 1.11 2009/01/07 21:25:34 billl Exp $

#include <stdlib.h>
#include <math.h>
#include <limits.h> /* contains LONG_MAX */
#include <time.h>
#include <sys/time.h> 
#include <values.h>

typedef struct LISTVEC {
  int isz;
  double** pv;
  unsigned int* plen;
  unsigned int* pbuflen;
} ListVec;

typedef struct BVEC {
 int size;
 int bufsize;
 short *x;
 Object* o;
} bvec;

#define BYTEHEADER int _II__;  char *_IN__; char _OUT__[16]; int BYTESWAP_FLAG=0;
#define BYTESWAP(_X__,_TYPE__) \
    if (BYTESWAP_FLAG == 1) { \
	_IN__ = (char *) &(_X__); \
	for (_II__=0;_II__<sizeof(_TYPE__);_II__++) { \
		_OUT__[_II__] = _IN__[sizeof(_TYPE__)-_II__-1]; } \
	(_X__) = *((_TYPE__ *) &_OUT__); \
    }

#define UNCODE(_X_,_J_,_Y_) {(_Y_)=floor((_X_)/sc[(_J_)])/sc[4]; \
                             (_Y_)=floor(sc[4]*((_Y_)-floor(_Y_))+0.5);}

#define	SQRT2PI		2.5066282746
#define VRRY 200
#define ISVEC(_OB__) (strncmp(hoc_object_name(_OB__),"Vector",6)==0)

// Andre Fentons cast designations
typedef	unsigned char	ui1;	/* one byte unsigned integer */
typedef	char		si1;	/* one byte signed integer */
typedef unsigned short	ui2;	/* two byte unsigned integer */
typedef short		si2;	/* two byte signed integer */
typedef unsigned int	ui4;	/* four byte unsigned integer */ 
typedef int		si4;	/* four byte signed integer */ 
typedef float		sf4;	/* four byte signed floating point number */ 
typedef double		sf8;	/* eight byte signed floating point number */ 

extern double *vector_newsize();
extern unsigned int scrsz;
extern unsigned int *scr;
extern unsigned int *scrset(int);
extern double BVBASE;
extern double* hoc_pgetarg();
extern void hoc_notify_iv();
extern double hoc_call_func(Symbol*, int narg);
extern FILE* hoc_obj_file_arg(int narg);
extern Object** hoc_objgetarg();
char** hoc_pgargstr();
extern void vector_resize();
extern int vector_instance_px();
extern void* vector_arg();
extern double* vector_vec();
extern double hoc_epsilon;
extern int stoprun;
extern void set_seed();
extern double mcell_ran4();
extern int nrn_mlh_gsort();
extern int ivoc_list_count(Object*);
extern Object* ivoc_list_item(Object*, int);
extern int list_vector_px2();
extern int hoc_is_double_arg(int narg);
extern Symbol *hoc_get_symbol(char *);
extern Symbol *hoc_lookup(const char*);
extern Point_process* ob2pntproc(Object*);

extern char* hoc_object_name(Object*);
extern int cmpdfn();
extern int openvec(int, double **);
int list_vector_px();
double *list_vector_resize();
static void hxe() { hoc_execerror("",0); }
extern void FreeListVec(ListVec** pp);
extern ListVec* AllocListVec(Object* p);
extern ListVec* AllocILV(Object*, int, double *);
void FillListVec(ListVec* p,double dval);
extern short *nrn_artcell_qindex_;
extern double nrn_event_queue_stats(double*);
extern void clear_event_queue();

static double sc[6];
