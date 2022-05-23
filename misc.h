// $Id: misc.h,v 1.11 2009/01/07 21:25:34 billl Exp $

#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <limits.h> /* contains LONG_MAX */
#include <time.h>
#include <sys/time.h>

typedef struct BVEC {
 int size;
 int bufsize;
 short *x;
 Object* o;
} bvec;

typedef struct {
  int isz;
  double** pv;
  int* plen;
} ListVec;

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

double *vector_newsize(void* vv, int n);
extern unsigned int scrsz;
extern unsigned int *scr;
extern unsigned int *scrset(int);
extern double BVBASE;
#ifndef NRN_VERSION_GTEQ_8_2_0
extern double* hoc_pgetarg();
extern void hoc_notify_iv();
extern double hoc_call_func(Symbol*, int narg);
extern FILE* hoc_obj_file_arg(int narg);
extern Object** hoc_objgetarg();
char *gargstr();
char** hoc_pgargstr();
extern void vector_resize();
extern int vector_instance_px();
extern void* vector_arg();
extern double* vector_vec();
extern double hoc_epsilon;
extern int stoprun;
extern void set_seed();
extern double mcell_ran4(unsigned int* idum,double* ran_vec,unsigned int n,double range);
extern int nrn_mlh_gsort();
extern int ivoc_list_count(Object*);
extern Object* ivoc_list_item(Object*, int);
extern int hoc_is_double_arg(int narg);
extern int hoc_is_tempobj_arg(int narg);
extern Symbol *hoc_get_symbol(char *);
extern Symbol *hoc_lookup(const char*);
extern Point_process* ob2pntproc(Object*);

extern char* hoc_object_name(Object*);
int list_vector_px();
extern short *nrn_artcell_qindex_;
extern double nrn_event_queue_stats(double*);
extern void clear_event_queue();
extern Objectdata *hoc_objectdata;
#endif

extern int cmpdfn(double a, double b);
extern unsigned int hashseed2 (int na, double* x);
extern int list_vector_px2(Object *ob, int i, double** px, void** vv);
extern int list_vector_px3 (Object *ob, int i, double** px, void** vv);
extern int list_vector_px4 (Object *ob, int i, double** px, unsigned int n);
extern void mcell_ran4_init(uint32_t idum);
extern int openvec(int, double **);
extern void cvode_fadvance(double);
int list_vector_px(Object *ob, int i, double** px);
double *list_vector_resize(Object *ob, int i, int sz);
int uniq2 (int n, double *x, double *y, double *z);
static void hxe() { hoc_execerror("",0); }
static double sc[6];

ListVec* AllocListVec(Object* p);
ListVec* AllocILV(Object* p, int nx, double *x);
void FillListVec(ListVec* p,double dval);
void FreeListVec(ListVec** pp);

