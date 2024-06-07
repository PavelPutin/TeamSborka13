#include <uf.h>
#include <uf_modl.h>
#include <uf_curve.h>
#include <uf_part.h>
#include <uf_object_types.h>


void ufusr(char* param, int* retcode, int paramLen) {
	UF_initialize();

    tag_t Line1;
	UF_CURVE_line_t l1;
	l1.start_point[0] = 0;
	l1.start_point[1] = 14.5;
	l1.start_point[2] = 0;
	l1.end_point[0] = 0; 
	l1.end_point[1] = 20.25;
	l1.end_point[2] = 0;
    UF_CURVE_create_line(&l1, &Line1);

	tag_t Line2;
	UF_CURVE_line_t l2;
	l2.start_point[0] = 0;
	l2.start_point[1] = 20.25;
	l2.start_point[2] = 0;
	l2.end_point[0] = 2;
	l2.end_point[1] = 20.25;
	l2.end_point[2] = 0;
	UF_CURVE_create_line(&l2, &Line2);

	tag_t Line1_2;
	UF_CURVE_line_t l1_2;
	l1_2.start_point[0] = 2;
	l1_2.start_point[1] = 20.25;
	l1_2.start_point[2] = 0;
	l1_2.end_point[0] = 4;
	l1_2.end_point[1] = 22.25;
	l1_2.end_point[2] = 0;
	UF_CURVE_create_line(&l1_2, &Line1_2);

	tag_t Line3;
	UF_CURVE_line_t l3;
	l3.start_point[0] = 4;
	l3.start_point[1] = 22.25;
	l3.start_point[2] = 0;
	l3.end_point[0] = 4;
	l3.end_point[1] = 60;
	l3.end_point[2] = 0;
	UF_CURVE_create_line(&l3, &Line3);

	tag_t Line4;
	UF_CURVE_line_t l4;
	l4.start_point[0] = 4;
	l4.start_point[1] = 60;
	l4.start_point[2] = 0;
	l4.end_point[0] = 8;
	l4.end_point[1] = 60;
	l4.end_point[2] = 0;
	UF_CURVE_create_line(&l4, &Line4);

	tag_t Line5;
	UF_CURVE_line_t l5;
	l5.start_point[0] = 8;
	l5.start_point[1] = 60;
	l5.start_point[2] = 0;
	l5.end_point[0] = 8;
	l5.end_point[1] = 56;
	l5.end_point[2] = 0;
	UF_CURVE_create_line(&l5, &Line5);

	tag_t Line6;
	UF_CURVE_line_t l6;
	l6.start_point[0] = 8;
	l6.start_point[1] = 56;
	l6.start_point[2] = 0;
	l6.end_point[0] = 50;
	l6.end_point[1] = 56;
	l6.end_point[2] = 0;
	UF_CURVE_create_line(&l6, &Line6);

	tag_t Line7;
	UF_CURVE_line_t l7;
	l7.start_point[0] = 50;
	l7.start_point[1] = 56;
	l7.start_point[2] = 0;
	l7.end_point[0] = 50;
	l7.end_point[1] = 60;
	l7.end_point[2] = 0;
	UF_CURVE_create_line(&l7, &Line7);

	tag_t Line8;
	UF_CURVE_line_t l8;
	l8.start_point[0] = 50;
	l8.start_point[1] = 60;
	l8.start_point[2] = 0;
	l8.end_point[0] = 54;
	l8.end_point[1] = 60;
	l8.end_point[2] = 0;
	UF_CURVE_create_line(&l8, &Line8);

	tag_t Line9;
	UF_CURVE_line_t l9;
	l9.start_point[0] = 54;
	l9.start_point[1] = 60;
	l9.start_point[2] = 0;
	l9.end_point[0] = 54;
	l9.end_point[1] = 49;
	l9.end_point[2] = 0;
	UF_CURVE_create_line(&l9, &Line9);

	tag_t Line9_10;
	UF_CURVE_line_t l9_10;
	l9_10.start_point[0] = 54;
	l9_10.start_point[1] = 49;
	l9_10.start_point[2] = 0;
	l9_10.end_point[0] = 52;
	l9_10.end_point[1] = 47;
	l9_10.end_point[2] = 0;
	UF_CURVE_create_line(&l9_10, &Line9_10);

	tag_t Line10;
	UF_CURVE_line_t l10;
	l10.start_point[0] = 52;
	l10.start_point[1] = 47;
	l10.start_point[2] = 0;
	l10.end_point[0] = 20;
	l10.end_point[1] = 47;
	l10.end_point[2] = 0;
	UF_CURVE_create_line(&l10, &Line10);

	tag_t Line10_11;
	UF_CURVE_line_t l10_11;
	l10_11.start_point[0] = 20;
	l10_11.start_point[1] = 47;
	l10_11.start_point[2] = 0;
	l10_11.end_point[0] = 18;
	l10_11.end_point[1] = 45;
	l10_11.end_point[2] = 0;
	UF_CURVE_create_line(&l10_11, &Line10_11);

	tag_t Line11;
	UF_CURVE_line_t l11;
	l11.start_point[0] = 18;
	l11.start_point[1] = 45;
	l11.start_point[2] = 0;
	l11.end_point[0] = 18;
	l11.end_point[1] = 31;
	l11.end_point[2] = 0;
	UF_CURVE_create_line(&l11, &Line11);

	tag_t Line11_12;
	UF_CURVE_line_t l11_12;
	l11_12.start_point[0] = 18;
	l11_12.start_point[1] = 31;
	l11_12.start_point[2] = 0;
	l11_12.end_point[0] = 20;
	l11_12.end_point[1] = 29;
	l11_12.end_point[2] = 0;
	UF_CURVE_create_line(&l11_12, &Line11_12);

	tag_t Line12;
	UF_CURVE_line_t l12;
	l12.start_point[0] = 20;
	l12.start_point[1] = 29;
	l12.start_point[2] = 0;
	l12.end_point[0] = 76;
	l12.end_point[1] = 26;
	l12.end_point[2] = 0;
	UF_CURVE_create_line(&l12, &Line12);

	tag_t Line13;
	UF_CURVE_line_t l13;
	l13.start_point[0] = 76;
	l13.start_point[1] = 26;
	l13.start_point[2] = 0;
	l13.end_point[0] = 80;
	l13.end_point[1] = 23;
	l13.end_point[2] = 0;
	UF_CURVE_create_line(&l13, &Line13);

	tag_t Line14;
	UF_CURVE_line_t l14;
	l14.start_point[0] = 80;
	l14.start_point[1] = 23;
	l14.start_point[2] = 0;
	l14.end_point[0] = 80;
	l14.end_point[1] = 14.5;
	l14.end_point[2] = 0;
	UF_CURVE_create_line(&l14, &Line14);

	tag_t Line15;
	UF_CURVE_line_t l15;
	l15.start_point[0] = 80;
	l15.start_point[1] = 14.5;
	l15.start_point[2] = 0;
	l15.end_point[0] = 0;
	l15.end_point[1] = 14.5;
	l15.end_point[2] = 0;
	UF_CURVE_create_line(&l15, &Line15);


	UF_FEATURE_SIGN sign = UF_NULLSIGN;
	uf_list_p_t REv1;// = Line1, Line2, Line3, Line4, Line5, Line6, Line7, Line8, Line9, Line10, Line11, Line12, Line13, Line14, Line15;
	UF_MODL_create_list(&REv1);
	UF_MODL_put_list_item(REv1, Line1);
	UF_MODL_put_list_item(REv1, Line2);
	UF_MODL_put_list_item(REv1, Line1_2);
	UF_MODL_put_list_item(REv1, Line3);
	UF_MODL_put_list_item(REv1, Line4);
	UF_MODL_put_list_item(REv1, Line5);
	UF_MODL_put_list_item(REv1, Line6);
	UF_MODL_put_list_item(REv1, Line7);
	UF_MODL_put_list_item(REv1, Line8);
	UF_MODL_put_list_item(REv1, Line9);
	UF_MODL_put_list_item(REv1, Line10);
	UF_MODL_put_list_item(REv1, Line9_10);
	UF_MODL_put_list_item(REv1, Line11);
	UF_MODL_put_list_item(REv1, Line10_11);
	UF_MODL_put_list_item(REv1, Line12);
	UF_MODL_put_list_item(REv1, Line11_12);
	UF_MODL_put_list_item(REv1, Line13);
	UF_MODL_put_list_item(REv1, Line14);
	UF_MODL_put_list_item(REv1, Line15);
	char rev1s[15] = "0";
	char rev1e[15] = "360.0";
	char* RevLimit[2] = { rev1s, rev1e };
	double revpoint[3] = { 0.0,0.0,0.0 };
	double revdir[3] = { 1.0,0.0,0.0 };
	uf_list_p_t RevFeatureList;
	UF_MODL_create_revolved(REv1, RevLimit, revpoint, revdir, sign, &RevFeatureList);
	UF_MODL_delete_list(&RevFeatureList);
	UF_MODL_delete_list(&REv1);


	UF_FEATURE_SIGN sign_negative = UF_NEGATIVE;
	double cyl_orig[3] = { 64.3,13.0,0.0 };
	char height[125] = "16.4";
	char diam[125] = "8.6";
	double direction[3] = { 0.0, 1.0, 0.0 };
	tag_t cyl_obj;
	UF_MODL_create_cyl1(sign_negative, cyl_orig, height, diam, direction,&cyl_obj);


	UF_terminate();
}

int ufusr_ask_unload(void) {
	return (UF_UNLOAD_IMMEDIATELY);
}