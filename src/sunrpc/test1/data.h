/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _DATA_H_RPCGEN
#define _DATA_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define FOO 100
#include <floatingpoint.h> /* required under Solaris 2.6 */

enum color {
	RED = 1,
	GREEN = 2,
	BLUE = 3,
};
typedef enum color color;

struct union_arg {
	int status;
	union {
		int intval;
		float floatval;
	} union_arg_u;
};
typedef struct union_arg union_arg;

struct square_in {
	char char_arg;
	short short_arg;
	int int_arg;
	long long_arg;
	quad_t hyper_arg;
	u_char uchar_arg;
	u_short ushort_arg;
	u_int uint_arg;
	u_long ulong_arg;
	u_quad_t uhyper_arg;
	float float_arg;
	double double_arg;
	quadruple quad_arg;
	bool_t bool_arg;
	color color_arg;
	char *vstring_arg;
	char fopaque_arg[10];
	struct {
		u_int vopaque_arg_len;
		char *vopaque_arg_val;
	} vopaque_arg;
	short fshort_arg[4];
	struct {
		u_int vshort_arg_len;
		long *vshort_arg_val;
	} vshort_arg;
};
typedef struct square_in square_in;

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_color (XDR *, color*);
extern  bool_t xdr_union_arg (XDR *, union_arg*);
extern  bool_t xdr_square_in (XDR *, square_in*);

#else /* K&R C */
extern bool_t xdr_color ();
extern bool_t xdr_union_arg ();
extern bool_t xdr_square_in ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_DATA_H_RPCGEN */
