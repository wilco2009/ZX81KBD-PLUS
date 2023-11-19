/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "//vmware-host/Shared Folders/OneDrive/Documentos/GitHub/ZX81KBD-PLUS/ZX81KBD-PLUS/zx81kbdtb.v";
static unsigned int ng1[] = {255U, 0U};
static unsigned int ng2[] = {0U, 0U};
static unsigned int ng3[] = {254U, 0U};
static unsigned int ng4[] = {1U, 0U};
static unsigned int ng5[] = {253U, 0U};
static unsigned int ng6[] = {251U, 0U};
static unsigned int ng7[] = {247U, 0U};
static unsigned int ng8[] = {239U, 0U};
static unsigned int ng9[] = {223U, 0U};
static unsigned int ng10[] = {191U, 0U};
static unsigned int ng11[] = {127U, 0U};
static unsigned int ng12[] = {31U, 0U};
static int ng13[] = {0, 0};
static int ng14[] = {1, 0};
static unsigned int ng15[] = {6U, 0U};
static unsigned int ng16[] = {24U, 0U};
static unsigned int ng17[] = {30U, 0U};
static unsigned int ng18[] = {11U, 0U};



static int sp_read_keys(char *t1, char *t2)
{
    int t0;
    char *t3;
    char *t4;
    char *t5;
    char *t6;

LAB0:    t0 = 1;
    t3 = (t2 + 28U);
    t4 = *((char **)t3);
    if (t4 == 0)
        goto LAB2;

LAB3:    goto *t4;

LAB2:    t4 = (t1 + 484);
    xsi_vlog_subprogram_setdisablestate(t4, &&LAB4);
    xsi_set_current_line(53, ng0);

LAB5:    xsi_set_current_line(54, ng0);
    t5 = ((char*)((ng1)));
    t6 = (t1 + 1360);
    xsi_vlogvar_assign_value(t6, t5, 0, 0, 8);
    xsi_set_current_line(55, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1452);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(56, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1544);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(57, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB6;
    t0 = 1;

LAB1:    return t0;
LAB4:    xsi_vlog_dispose_subprogram_invocation(t2);
    t4 = (t2 + 28U);
    *((char **)t4) = &&LAB2;
    t0 = 0;
    goto LAB1;

LAB6:    xsi_set_current_line(58, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(59, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB7;
    t0 = 1;
    goto LAB1;

LAB7:    xsi_set_current_line(60, ng0);
    t4 = ((char*)((ng3)));
    t5 = (t1 + 1360);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(61, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB8;
    t0 = 1;
    goto LAB1;

LAB8:    xsi_set_current_line(62, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(63, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB9;
    t0 = 1;
    goto LAB1;

LAB9:    xsi_set_current_line(64, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(65, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB10;
    t0 = 1;
    goto LAB1;

LAB10:    xsi_set_current_line(66, ng0);
    t4 = ((char*)((ng5)));
    t5 = (t1 + 1360);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(67, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB11;
    t0 = 1;
    goto LAB1;

LAB11:    xsi_set_current_line(68, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(69, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB12;
    t0 = 1;
    goto LAB1;

LAB12:    xsi_set_current_line(70, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(71, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB13;
    t0 = 1;
    goto LAB1;

LAB13:    xsi_set_current_line(72, ng0);
    t4 = ((char*)((ng6)));
    t5 = (t1 + 1360);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(73, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB14;
    t0 = 1;
    goto LAB1;

LAB14:    xsi_set_current_line(74, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(75, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB15;
    t0 = 1;
    goto LAB1;

LAB15:    xsi_set_current_line(76, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(77, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB16;
    t0 = 1;
    goto LAB1;

LAB16:    xsi_set_current_line(78, ng0);
    t4 = ((char*)((ng7)));
    t5 = (t1 + 1360);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(79, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB17;
    t0 = 1;
    goto LAB1;

LAB17:    xsi_set_current_line(80, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(81, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB18;
    t0 = 1;
    goto LAB1;

LAB18:    xsi_set_current_line(82, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(83, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB19;
    t0 = 1;
    goto LAB1;

LAB19:    xsi_set_current_line(84, ng0);
    t4 = ((char*)((ng8)));
    t5 = (t1 + 1360);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(85, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB20;
    t0 = 1;
    goto LAB1;

LAB20:    xsi_set_current_line(86, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(87, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB21;
    t0 = 1;
    goto LAB1;

LAB21:    xsi_set_current_line(88, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(89, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB22;
    t0 = 1;
    goto LAB1;

LAB22:    xsi_set_current_line(90, ng0);
    t4 = ((char*)((ng9)));
    t5 = (t1 + 1360);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(91, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB23;
    t0 = 1;
    goto LAB1;

LAB23:    xsi_set_current_line(92, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(93, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB24;
    t0 = 1;
    goto LAB1;

LAB24:    xsi_set_current_line(94, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(95, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB25;
    t0 = 1;
    goto LAB1;

LAB25:    xsi_set_current_line(96, ng0);
    t4 = ((char*)((ng10)));
    t5 = (t1 + 1360);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(97, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB26;
    t0 = 1;
    goto LAB1;

LAB26:    xsi_set_current_line(98, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(99, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB27;
    t0 = 1;
    goto LAB1;

LAB27:    xsi_set_current_line(100, ng0);
    t4 = ((char*)((ng2)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(101, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB28;
    t0 = 1;
    goto LAB1;

LAB28:    xsi_set_current_line(102, ng0);
    t4 = ((char*)((ng11)));
    t5 = (t1 + 1360);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 8);
    xsi_set_current_line(103, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB29;
    t0 = 1;
    goto LAB1;

LAB29:    xsi_set_current_line(104, ng0);
    t4 = ((char*)((ng4)));
    t5 = (t1 + 1636);
    xsi_vlogvar_assign_value(t5, t4, 0, 0, 1);
    xsi_set_current_line(105, ng0);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    xsi_process_wait(t5, 10000LL);
    *((char **)t3) = &&LAB30;
    t0 = 1;
    goto LAB1;

LAB30:    goto LAB4;

}

static void Always_109_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;

LAB0:    t1 = (t0 + 2252U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(109, ng0);

LAB4:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 2152);
    t3 = (t0 + 484);
    t4 = xsi_create_subprogram_invocation(t2, 0, t0, t3, 0, 0);
    xsi_vlog_subprogram_pushinvocation(t3, t4);

LAB7:    t5 = (t0 + 2204);
    t6 = *((char **)t5);
    t7 = (t6 + 44U);
    t8 = *((char **)t7);
    t9 = (t8 + 148U);
    t10 = *((char **)t9);
    t11 = (t10 + 0U);
    t12 = *((char **)t11);
    t13 = ((int  (*)(char *, char *))t12)(t0, t6);

LAB9:    if (t13 != 0)
        goto LAB10;

LAB5:    t6 = (t0 + 484);
    xsi_vlog_subprogram_popinvocation(t6);

LAB6:    t14 = (t0 + 2204);
    t15 = *((char **)t14);
    t14 = (t0 + 484);
    t16 = (t0 + 2152);
    t17 = 0;
    xsi_delete_subprogram_invocation(t14, t15, t0, t16, t17);
    goto LAB2;

LAB8:;
LAB10:    t5 = (t0 + 2252U);
    *((char **)t5) = &&LAB7;

LAB1:    return;
}

static void Initial_113_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;

LAB0:    t1 = (t0 + 2396U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(113, ng0);

LAB4:    xsi_set_current_line(115, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1084);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(116, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1268);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(118, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1360);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 8);
    xsi_set_current_line(119, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1452);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(120, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1544);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(121, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1636);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(127, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1268);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(128, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB6;
    goto LAB1;

LAB6:    xsi_set_current_line(129, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1268);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(130, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB7;
    goto LAB1;

LAB7:    xsi_set_current_line(131, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB8;
    goto LAB1;

LAB8:    xsi_set_current_line(133, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(134, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(135, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1084);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(136, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB10:    xsi_set_current_line(137, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(138, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB11:    xsi_set_current_line(139, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(140, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB12;
    goto LAB1;

LAB12:    xsi_set_current_line(141, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1084);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(142, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB13:    xsi_set_current_line(143, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(144, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB14:    xsi_set_current_line(145, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(146, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB15:    xsi_set_current_line(147, ng0);
    t2 = ((char*)((ng16)));
    t3 = (t0 + 1084);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB16:    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB17;
    goto LAB1;

LAB17:    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB18;
    goto LAB1;

LAB18:    xsi_set_current_line(153, ng0);
    t2 = ((char*)((ng17)));
    t3 = (t0 + 1084);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(154, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB19:    xsi_set_current_line(155, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(156, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB20;
    goto LAB1;

LAB20:    xsi_set_current_line(157, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(158, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB21;
    goto LAB1;

LAB21:    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 1084);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(160, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB22;
    goto LAB1;

LAB22:    xsi_set_current_line(161, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(162, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB23:    xsi_set_current_line(163, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(164, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB24;
    goto LAB1;

LAB24:    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng18)));
    t3 = (t0 + 1084);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(166, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB25;
    goto LAB1;

LAB25:    xsi_set_current_line(167, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(168, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB26;
    goto LAB1;

LAB26:    xsi_set_current_line(169, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(170, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB27:    xsi_set_current_line(171, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1084);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(172, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB28;
    goto LAB1;

LAB28:    xsi_set_current_line(173, ng0);
    t2 = ((char*)((ng13)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(174, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB29;
    goto LAB1;

LAB29:    xsi_set_current_line(175, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1176);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(176, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB30;
    goto LAB1;

LAB30:    xsi_set_current_line(177, ng0);
    t2 = ((char*)((ng12)));
    t3 = (t0 + 1084);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 5);
    xsi_set_current_line(178, ng0);
    t2 = (t0 + 2296);
    xsi_process_wait(t2, 100000LL);
    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB31:    goto LAB1;

}


extern void work_m_00000000002113335398_0986573990_init()
{
	static char *pe[] = {(void *)Always_109_0,(void *)Initial_113_1};
	static char *se[] = {(void *)sp_read_keys};
	xsi_register_didat("work_m_00000000002113335398_0986573990", "isim/zx81kbdtb_isim_beh.exe.sim/work/m_00000000002113335398_0986573990.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
