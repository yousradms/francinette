#include "pf_utils.h"

void simple_test()
{
	TEST("no format", {
		test_printf_noarg("");
		test_printf_noarg("\x01\x02\a\v\b\f\r\n");
	})

	TEST("% format", {
		test_printf_noarg("%%");
		test_printf_noarg(" %%");
		test_printf_noarg("%%c");
		test_printf_noarg("%%%%%%");
		test_printf("%%%c", 'x');
	})
}

void test_c()
{
	TEST("c format", {
		test_printf("%c", 'x');
		test_printf(" %c", 'x');
		test_printf("%c ", 'x');
		test_printf("%c%c%c", 'a', '\t', 'b');
		test_printf("%cc%cc%c", 'a', '\t', 'b');
		test_printf("%cs%cs%c", 'c', 'b', 'a');
	})
}

void test_s()
{
	TEST("s format", {
		test_printf("%s", "");
		test_printf("%s", (char *)NULL);
		test_printf("%s", "some string with %s hehe");
		test_printf(" %s", "can it handle \t and \n?");
		test_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
		test_printf("%s%s%s", "And ", "some", "joined");
		test_printf("%ss%ss%ss", "And ", "some other", "joined");
	})
}

void test_p()
{
	TEST("p format", {
		test_printf("%p", "");
		test_printf("%p", NULL);
		test_printf("%p", (void *)-14523);
		test_printf("0x%p-", (void *)ULONG_MAX);
		test_printf("%pp%p%p", (void *)LONG_MAX + 423856, (void *)0, (void *)INT_MAX);
	})
}

void test_d()
{
	TEST("d format", {
		test_printf("%d", 0);
		test_printf("%d", -10);
		test_printf("%d", -200000);
		test_printf("%d", -6000023);
		test_printf("%d", 10);
		test_printf("%d", 10000);
		test_printf("%d", 100023);
		test_printf("%d", INT_MAX);
		test_printf("%d", INT_MIN);
		test_printf("dgs%dxx", 10);
		test_printf("%d%dd%d", 1, 2, -3);
	})
}

void test_i()
{
	TEST("i format", {
		test_printf("%i", 0);
		test_printf("%i", -10);
		test_printf("%i", -200000);
		test_printf("%i", -6000023);
		test_printf("%i", 10);
		test_printf("%i", 10000);
		test_printf("%i", 100023);
		test_printf("%i", INT_MAX);
		test_printf("%i", INT_MIN);
		test_printf("dgs%ixx", 10);
		test_printf("%i%ii%i", 1, 2, -3);
	})
}

void test_u()
{
	TEST("u format", {
		test_printf("%u", 0);
		test_printf("%u", -10);
		test_printf("%u", -200000);
		test_printf("%u", -6000023);
		test_printf("%u", 10);
		test_printf("%u", 10000);
		test_printf("%u", 100023);
		test_printf("%u", INT_MAX);
		test_printf("%u", INT_MIN);
		test_printf("%u", UINT_MAX);
		test_printf("dgs%uxx", 10);
		test_printf("%u%uu%u", 1, 2, -3);
	})
}

void test_x()
{
	TEST("x format", {
		test_printf("%x", 0);
		test_printf("%x", -10);
		test_printf("%x", -200000);
		test_printf("%x", -6000023);
		test_printf("%x", 10);
		test_printf("%x", 10000);
		test_printf("%x", 100023);
		test_printf("%x", 0xabcdef);
		test_printf("%x", 0x7fedcba1);
		test_printf("%x", INT_MAX);
		test_printf("%x", INT_MIN);
		test_printf("%x", UINT_MAX);
		test_printf("dgs%xxx", 10);
		test_printf("%x%xx%x", 1, 2, -3);
	})
}

void test_X()
{
	TEST("X format", {
		test_printf("%X", 0);
		test_printf("%X", -10);
		test_printf("%X", -200000);
		test_printf("%X", -6000023);
		test_printf("%X", 10);
		test_printf("%X", 10000);
		test_printf("%X", 100023);
		test_printf("%X", 0xabcdef);
		test_printf("%X", 0x7fedcba1);
		test_printf("%X", INT_MAX);
		test_printf("%X", INT_MIN);
		test_printf("%X", UINT_MAX);
		test_printf("dgs%Xxx", 10);
		test_printf("%X%Xx%X", 1, 2, -3);
	})
}

int main(int argn, char **argv)
{
	printf(YEL "Mandatory:" NC "\n");
	pf_setup_framework(argn, argv);

	simple_test();
	test_c();
	test_s();
	test_p();
	test_d();
	test_i();
	test_u();
	test_x();
	test_X();

	TEST("random", {
		// generated in python
				/* 2 */ test_printf_silent("[+:y+b?-%iPBhl%dn0#L%u/qq%%~)kDca^y", -504253072, -57369566, -103488063);
		/* 3 */ test_printf_silent("%dAd|IH%xW%X%X}]%sxn`KTiyZ]%c#U _]{w%i-Z\tKBE%c8LUK9STol\n%iVz%X\r1L6Dl1EL", 1799947596, -1294581918, 413988239, 1303484551, "wWZ!7'\\wT\n3.TaJALykB^kDQ)\nA%cyQs\"w\tUU|\"^ih.]W\t>wck%!jUu *ZILp2;7&$B2\fjH}LaCZBxFg0)F3W302IxOv ,ijkIK", -1418485862, 222795749, -1039753087, -1208335165, -1008709084);
		/* 4 */ test_printf_silent("O28mc/O%%}(9\r}%xuxP %x%%%d8K5F%% X=8@t@8%ud 4;Ejh<,%scj;4jW]%i\t:tn%dR+-J<", 910111713, -646020660, -1388936832, 1204812253, "l@gG<\"P,+@\nV(oo6_E{B5N`J7Y&uR}=i4lL'P1zgn#=e.&Fh*9/ On/}&EqmC{\"Tx>H-#|ApS8N\fllxR^f", -1583800092, 1111985633);
		/* 5 */ test_printf_silent("BS\r7Tc?Ol,%%%sM<%xDce6>l5gWW%%P{%uP7\\", "BNlMCe", -1793701342, -1097619846);
		/* 6 */ test_printf_silent("ia<Xv4Y&j%dvU]i:%%\t%dNvwMA", 43589815, -303924442);
		/* 7 */ test_printf_silent("yYZCsyt^Xa%p%uzwL%xV|?%dj%p\f+anH F%x9%cY#`[u#;?f~%sN<57U%cqX", (void *)3361998141424127239, -1339489601, 1687346346, -1379707401, (void *)-4571952870105221301, -1437207450, 1654689875, "~St{Z%tl,Eg|1OD7R$O-", -742972902);
		/* 8 */ test_printf_silent("-GN%skEd%u}d}B6csNd", "OdH^jCU#hyy]FV^f==Ys-fz7y-F\"p", -886319256);
		/* 9 */ test_printf_silent("%s3K6JrT%pf>*B6\v~%cPj%ces5Eh\",", "X/(tj HbseBK~<x^E|\fm%:y1c(/}W\nR%|ue@KP3H?l>;\t]uZ\v{\v)ZWg#bG\nfQ\n(V}w.iIZ^1xbn5Kg6IzV}`EJGt1;\\,Z'A:zV", (void *)157996135357289542, 1350577430, -219197765);
		/* 10 */ test_printf_silent("%x@,0%c-QO)C%c\f>\"%sw(A)-Wr%cxp\raO{> b\v%x%u{l%uoB@", 999226823, -1783768461, 1754770540, "VcfNhKa{&zBKz-pr;RkJ J*GCwVGs!^_uB?7BS\n1Ys,?in!7BU6=>\v\"AHf4@|JkMdU_#-\r*eb[oC%+JoNyIaaQu+zj", 220672391, 1364280058, -1873385467, -1148561829);
		/* 11 */ test_printf_silent("%pgw8^%uyzB%xHSSxtZ:L\"%u%i%s-%xz%xe n)f</tP%dw !u#q]E%u> (", (void *)-3605745943455915456, 1337196149, -1332476763, 669951657, 160362378, ",v*Mx@-)&W,pHI^E\vGLwPA`ckEnmR5:RIJU:yc^\rJP):;[yK", 419590518, -143288617, 868552100, 1008170208);
		/* 12 */ test_printf_silent("_:hW%%Q: lN\\5[P%u5\v4X\nD", -1852107062);
		/* 13 */ test_printf_silent("<\n0\v K%x0p#^wvQc\v%Xk~*PR_m2&\f%cR%XpU5om~;NOW%iIh%X8~\v\"%sg%iG}X%xNL", 2107728332, -1374822411, -1085596163, -1162949993, 641520407, -530920544, "bbzT<Iwrr_ Ic^6@2Z0C+!vvl.\"m\"", -544924380, -912935117);
		/* 14 */ test_printf_silent("%cg{&dT\v%iWh4`H%sHLluZt%X=`S=5s]%p^Hb%dJ2\v%Xv\nnX%u4jGZy$%sQ4.)+Z)6p", -1749762329, 733019405, "u7+iEO50.%J_+Vf+X-aG%&\f.:nd_82gU7ybUR{SOh@'c", -662460034, (void *)5783750945033035077, -514065750, 88676215, 1671743940, ",SX~h~M=Os9XCxVOi]t\t'I~$");
		/* 15 */ test_printf_silent("%ii,7_9sH%XZL@n%i}mY@z%XN >wFh:xt%u3?9_=5AT%pi\nD$3[/#se", -161976507, -2124783168, 1344693115, -980076850, -1525221034, (void *)7393087513237711572);
		/* 16 */ test_printf_silent("%s%X'F;e%xYo<t9/\nP%xCb iv4!KSS", "\fw>fBGq)xtvi-lul/Y\\\rB2!#u*l(CW8Z-90[*", 838172244, 308222982, -479505070);
		/* 17 */ test_printf_silent("NE9%iy 9+%drMR&%uDvEJS%s%%%xp'd&H{*\t_p%sB#t22+4%p+n%pJdq.9[Gl+Y%iea", -1915360328, -1598554117, -2028805532, "TY;RCJ+nMw{kSrYT\rgF0y1U9(X)U=\r}t3Bsba'J*an__U#>shPGT8KA6PHKR8qTn:XO8hJcM`giNG", -362100669, "%1&=Sqo4n75%VhVf{", (void *)-2106143232535281445, (void *)9018288960394660364, 1745691639);
		/* 18 */ test_printf_silent("2$^\nr%u9A-&~bb%u\\bf[", -1871356951, 1097008601);
		/* 19 */ test_printf_silent("J:2 \ft}%X<zg\t]&ddQ%pUHh@q%dmm\n%d`-", 1985009599, (void *)-6411970026211733651, 1712297029, -676279158);
		/* 20 */ test_printf_silent(" jOJp3|%c, Pm+%um5ECX%%|s_l{%%[B-W-:%p0%i2,%d(gR%p;%d.LZ@", -61853156, -997061459, (void *)-6521296009528619510, 1613573846, -30640477, (void *)-7730853415869479193, -1915702811);
		/* 21 */ test_printf_silent("%sNQ/[o<}%%YXXQ^Y%x%uDy9}8T%c%XaeE\vr%%\tDr8\\w%d7h\rni%u@ Z!", "@\fWnp,\f\r:iI%%L]@U(,.wH>^l\tIa%\v*H\f7uhl09-m", 1979478833, -1900070644, -163292008, -707722479, 559117305, 1773301595);
		/* 22 */ test_printf_silent("e>kd\n/.{; %ikV%p&%c\n5RNCA%scLY;^9PV%dI48/lv#o<", -360831582, (void *)998510377582909932, -480713944, "{o\tKCY:p`. /q\"Tc\\+ATpKJuG\"\vYxeLQ%xd;G}\n)c@", -1748278087);
		/* 23 */ test_printf_silent("WZ7<:aDP%sShTG\frQ{%x4VPsY6Yq%cAdYC:QU%XaEp]3$\f\n%sn}2(x%c3&\rB9K\f\"IC%%A%dkOzN%%A\fK0P28%%N\vz#&Q@#=", "A3\v9jTY'LN[?~>1|1[b#~IJY=|zSd6_f}J\f}3OiIKbCpx^O@^XRl\t(0BIfJ|a6a=aw50S*^EcNs92%Q_<h", -112008073, -1621827129, 1544559520, "#N\"z(\rN8\vIMk8\"0k >.Ai/Cdq@#JGi\\uP:f8[p'.p\\S0r\\^$rNegonfbWSe%\tX\fJej4\n\"-m~OsKgo&oqT[ \fWS[2oQ*Th.ICG*fg", 1602129318, 426797514);
		/* 24 */ test_printf_silent(" 6`?%c)Z.&5f%s\"FF?H#C2T2%dF*lN%%p?5;hR6/\t", 1021367923, "1Bi\nHO9B~WXJ^$%Q\"-O?9s,zQ:!Ni#w%-,V&b)/#D7,V8-\r F><0Gwf!'qGP@3(:", 1397439970);
		/* 25 */ test_printf_silent("n^Zart@%dLbw [UEw%xS)\vM9zF^%cyiDLX%soQi5%Xz9#7TVfHiA%xsky?&pyT;%XF{qN&%Xp%c", -1208723736, -177651383, 610227395, ".CgD3VJiO,4j&IcN^av9sHB=5=Ib2\"e]%|EtKxG5mslT@0Ic^\"]I'iKbiU ZwB[:~vq#g", -1523547783, 1317011206, -922420036, -1242253953, 445211497);
		/* 26 */ test_printf_silent("$ySSb\n2y*@%cIYD#_M!%x{\ni(%dL%%\fF9e_!EHC%ip%d5t`m%c,\"Flv MIF", 99081783, -1226552010, 1408788525, -209555676, 612570816, -1884658065);
		/* 27 */ test_printf_silent("\\%d\"wIFs6/KxO%x.>\\[%dCFTu7O%dz%c[@3|4D6V%u%%o( P(tBHh", 257198818, 1460328938, 1647643389, 490080554, -1812827908, -920591469);
		/* 28 */ test_printf_silent("\\z#-8q%% G=3G %p_lI>?m\\hM%sT?Y!O@%i[nA!%p", (void *)-4766071865963824961, "+ptP!(iz0~\nFr>7|J9wr49YV<5fdwMHki8n;\fz=Y3US-", 282529547, (void *)2504837418730950085);
		/* 29 */ test_printf_silent("kw6Op>J[%cZ*w vO\ro%pTmhiVd#4Dv%x&\n!bkfez?t%X|%d", 1595492432, (void *)4178494163365760933, -727547061, 1053246052, 1924264293);
		/* 30 */ test_printf_silent("+6'1pe%cY89lFjD-%d\\ew~\nm#x%u8sW!2G=i?%s3Wy%x.R%i", -136862160, -2026571810, -1352881102, "+fc\r1swlu\tkyC/wheHQe3:g6a@<h\\@jD|^coeXHKt^n\"8+OB#nv i)lm`epKik|k+OzfK3%^Mq", 792000779, 891136767);
		/* 31 */ test_printf_silent("%%.)=TZ\\n.B%uHWXe.{,p%xRBiyAS~#9%u+On%sq]{\\#lq%ph%iYkA:sz80>%x9l'ny{~", -203225135, -1098342769, 343463162, "_T[E[gCpDjEdt(`xoU=G\n", (void *)2504601396462377827, -1556326390, -1847513475);
		/* 32 */ test_printf_silent("=7%xvy%x|%cdIk(We-", 2035179619, 728453159, -749080650);
		/* 33 */ test_printf_silent("\n?U)A9m%sb%d;;<{:$%u4%pTW>j<X8e%%rg%p)b40Q[7\v\t%X(zR\n)k,3%x%x+$mBs", "TjR+q^Y\nii\rV5 @\fJF\n$jva5VAi+jq|-|lMJ|@\r", -1951901888, -125017637, (void *)1923736464563924548, (void *)-683463789288588494, -1293606043, 785746166, -254916389);
		/* 34 */ test_printf_silent("\rU</%uGYKzc>Y\fb8%x%p0%xXb3v@z'|%x12@(Bi%s-v?F3Rs%s}lpoWVOK>%iy2]%uOFd\v\n", -1514572994, 564096656, (void *)-5342169233112659358, -1792959919, -1389759133, "A<Af6B-vv{aXsT\\3bT7v|i\\Y.hg@x*Saa[d2eJR1'x Hwj);|ZM9{}SyA\"L&\v9\vx*9i", "?uFirn(G.~#*6d\fv}F>;<jlx", -880005790, -168345477);
		/* 35 */ test_printf_silent("%chE%%<w.3/f%i|%c4#!I%X %x6#;c!aS5=%uVORyr", 2069552056, -1983339648, 995607053, -2140253728, 43830261, 1728510024);
		/* 36 */ test_printf_silent("\\yrt$`JI(%dq45fF%i%s?%dK\r74W%c'bvFFH", -815513331, 1695643265, "f;9!}OGoO#w?'1 yeT wn\\d$&R4xRz~z\vDy$0$yr<-7m\vAe\r:,uG2!tz^gdEhPmI\r&eEM,a$nZf", -728129067, 208881445);
		/* 37 */ test_printf_silent("cC!\r\f%s=DF>rv`d.\n%XmxT.,8B O%s%i^p8PN-;%d%c\f=lMU4%i/K%dp[", "-6?;EL:udEG|\"_4[5$\f@@i(P N\n:5iI\rKm8.[2\\]\\\tw", 328206976, "u$@S\t(`\vYH =R9I\\1>AU4", 44902987, 232723408, -661494849, 1126397550, 1572067723);
		/* 38 */ test_printf_silent("L@p%dyAG7%d9am%svw|xC&r%%ubt4\r\vP{+R%xI;ki \tQyvu%d|V9..%x[;dS0)%ir)YB*k%d3%u,ISpe5", -2120777353, 1981810229, "=BLWXrL@1u/j<SoKU\rc+W\"\\\th*rr}P(K'~Ks1sD\nP$}OGK3e~A\\C K0>h]VjZ+o/Th{!Y>EWH%v1A>IP$\fs2Ye1VnH", -166152441, 1770113325, 728501024, 587307808, 1567493787, 1774798235);
		/* 39 */ test_printf_silent("eNN&%s/uqH+\v,r%%%sn^!tr%d%ueJ^K(9D)%sjv8RL%p%dMj%p>\tS1\fCes%XO{PM", "Qr&?7Q(2376ic/8$S1fC\n:US{}KAx/K;Uy9a;, 0KcAK]\\axdEvUQY", "QLq5(8j2\fSpj#Uu*t5!/\\#uVD!OZj[h!Cx(>,lD", -231083701, -947101440, "7~rr#*}", (void *)-6812998588188630605, 1272730195, (void *)-7921979970571641460, -568074953);
		/* 40 */ test_printf_silent("5%iF%pz}\t\n5%dp'vyC", -1798881656, (void *)8712033396571996046, 894765646);
		/* 41 */ test_printf_silent("I(j%u;+}%iVC-rs%sm `]l~z%%}Sc\r\"'}%%JqdzrYdo~%x{:5W_\rq", 94753341, 897689204, ".7K$|\nG^zq\\,Lp&n", 192496777);
		/* 42 */ test_printf_silent("m?t*%X_e-K%dA`%iz\nFs&4%%@**F6%i_&\tW{ZL", -722780140, 2058794971, -1858638847, 1804521329);
		/* 43 */ test_printf_silent("dnQr%X%u_YvhV\vc/T`%p", -1066508724, 476441680, (void *)-4596077442028605639);
		/* 44 */ test_printf_silent("K.1y<OM2J6%uM;rsm>%p8[Q%XR#V%d|;EJd`uD%i<h$L", 1035666624, (void *)9049016467285305030, -1467865248, 1943063186, 1771573407);
		/* 45 */ test_printf_silent(", fJBhfCIO%c3DpsH\t%d", -1162772953, -582726298);
		/* 46 */ test_printf_silent("OO\"7GN%dI&{%Xt8%sv!$>$t%dFwE6HRtC>%dJ%XG*W^", 752352271, -1375810228, "k?oqd8}TLF<KO6n?\vE]\"<Jki\rZ)W#|Z8/\njqnbLoZ:z", 221661581, -1961436336, 527827529);
		/* 47 */ test_printf_silent(" 9ernt%x=P}.>{|yJS%d.p^}G+%s@%u\\-%px_iS\"2@54%p%if\tp^{4}p\v%X", -1562100883, -1886167739, "2\"X\r&MYM:t\"5\thjtJd\fb[BM89", 1096205773, (void *)-3874121030451341397, (void *)5749095664728981987, -243107190, 133600003);
		/* 48 */ test_printf_silent("p-2hiU%sN9s%s)tl2|nIJ`w%X%d\f+U!9IaS$o", "ZH1%H76o<\t^.x3~sWk@\n\\w9im`;~\n>U\\g\fhx<d2Q&,nTG2.~\vF", "6LNg|F\fHGg5b~<{FnR3\vKu-Y@cD>}QF)(x\f\f@ma>q5#2C~X?x1\vlB)65`I9VO3f#E9vG$p;z[efgdt!KfV(7AXn5$3K.R{m", -211837151, -1420598120);
		/* 49 */ test_printf_silent("MOi-nG%x%px%c&Kt%XK',X#N%i%X8hz(H{%iXZc%xbx%XZ.<8%pNhA0J,", 133971650, (void *)695740050303013280, 1934079036, 1731724991, -1845823168, -93518080, -54363558, 1636123633, 968002735, (void *)580285533850847485);
		/* 50 */ test_printf_silent("|!\"\vc&z\tDW%s\r-LZT&8@%d,sHA>%i\"W$RE#%dx^y1%%=OuJ$h%XU-|xF3 %s`^><D;U{%xWf", "|>SS~i0iS0o-jp$bXv_GH\tt`O*m>D[jid\t.-{:vdaj\ny\"tb", -2008758261, 651025635, -1951628510, 354346056, "po9AF&4I;:~&+~]a:-JhuN29nCi\ndOq:(Q", 1283881545);
		/* 51 */ test_printf_silent("Qz3]9ev%cK4%X?-X VTilIu%XvQHC%X&E@)-X%c33-%p3b\t/pdnsDf%st%cr$Mlr", 2137865843, 1323825614, -300367669, 96817451, 1930874416, (void *)352521652679507325, "U3Yw|k7/Oy$\n^M9){\vb$%^*ae6\f5\\qMdF_#Nfow:RzF@QpJU~Skc\foDf,-.cxJZ", -1788994652);
		/* 52 */ test_printf_silent("2!4m%s\r%djU\v Z%%/-\vIwkPp%sk^]Je>V+\r%dg#T0fXR%x\v[rQ68%p\n{!@%x]L!Z-", "g0{<a\"LG14r,N/,Gg3<I 8MZm-hFu\f+ue[&hw}3;%[<5{P=y2mG\t.([O&zi9.T4kWB_7}&vaV%Ew#", -1747998512, "XS{\r $o]6~f++\"S$8'ynkP?=1o(R#.3Q9|xP`*k\tR@<\\eJ\\^[w?\tU*@\"[;Mf#~&\rT@5AY\\jOrBp]=}nq}", 830881838, -411695541, (void *)-5958681363336472140, 1844250515);
		/* 53 */ test_printf_silent("Pr8*\rH1j/K%%3%XEpr%pM3\t%i,tB\v%d#oF*:ap>F\t%unN\v=\v%iufA%i78hBK\\\nTWP%cJ,Ev%i&0w\rzO5ZAa", 2120936617, (void *)2417730661915117141, -66877749, 1677176601, -235743556, 1977800904, 2124583767, -781572471, 418452185);
		/* 54 */ test_printf_silent(",s*E *%i$~hsK%Xf\rU[BI_j%s]y{|\t`%%Y>%XGO\\\\!saGg", -655375460, -1067841119, "8I~dF/A :m,g\t1Eu\nX|mlSgr.m", 1296735426);
		/* 55 */ test_printf_silent("K(V&[<=3U%i%X3rzpwNC%pT%i\fqL%pciRp[%sd)\r\v/%XNdr9lU4Qc%uo%s04&3.A 76g%XhF", -1227341295, 1555420807, (void *)191622112654254574, -1043774635, (void *)-5972859657780709489, "2Xm1p%p6)v:FhL^\ru$=ET\"CjgV&;v{U:qh[e\"7>XSPWWn s1l\tb3_A%\ntqwAc2F\n7/z3~(zRh^B!qO", 142826729, -1834241870, "GS\r4%}[5|n4pt\\o&;/Vq PK8y%pOHk\tx=R:\\UCW\t>LB>IoXO$L#irvU z#:\tg)2!ZnHPfJquWmiZm`W6hfC!I", -149699710);
		/* 56 */ test_printf_silent("[XWUu3hoMg%%#q^9\\tv~%suXUQ^mTs", ")\"G*''Zw)7zTK Hf\f-`3V>Hld(}IM{$Hk@=eEK>g");
		/* 57 */ test_printf_silent("Y@9%sh{uXI^`yk%p$Y Q,<%sJqU\r!yHg+)%p%dA\t%%3/P%Xko", "#k\tUFg", (void *)2624709044894453316, "'9k\"]#pmN@w\vN:CGI,sDh\rnpsc\rReh&QH54'^K\vAqO:AV',2?YRb`=*I3\t<Z**\v(v*J[Z`M<D\"`!Z`E,+*<+b|G?$^m", (void *)-4235954721881890248, 1724598348, 675916538);
		/* 58 */ test_printf_silent("v7%p>`f2%u@o]?;%d[l9n_D%x\v7C,h= J%iE$Ke/%dn7}%dX/(#'\n%cuSD", (void *)-5135556295349992961, -1331619580, -1070902010, -1645490286, -1410979246, -1242058762, 2113081709, 1820529899);
		/* 59 */ test_printf_silent("AOf:%x4%i't'J\fIio=%db_g7%u%c%i1ga&s|q&", 987311036, 2080209756, 253802541, 1071967968, -1487104232, -985009779);
		/* 60 */ test_printf_silent("doi\f []-f%%4J(;Xy,9%u!_\vc> j4%xr@  \"N-%d%uo%uN\\>oK\f ", 1058835347, 2109065352, 62755792, 208376123, -1271338847);
		/* 61 */ test_printf_silent("8Rl%sdXQyz%Xe@w%u[?,r>=U`%X\"$nj@k6+uj%X\rsT%%q$I6wP2%u.IH*NS&V%cAWXt``_$]%s!#6hT%d@z", "mdVS1>a}#bt-X@`Uw\"+\"\tWI%nt{4f8\t{\vn5_z**\v?$-\\\nB\r<Zk6.Xme<)lcBd(B6q/~7fG46X{hS8~DYsL_OPU\"g^,,<QNm", 1980524403, 7878189, -52309512, 1810402942, -793277899, 1809154413, "46FQ7M&,;elG:&pHP\n\\%o1\"2M<Y?B~Uw~B#y,@~2A}|\\\\G+qgUM~*cs.e1;PU)?1@`YMs2", 1125802297);
		/* 62 */ test_printf_silent("TB5mY(r@wv%cEpq|UV;%s.q)%s\nK~j~G%%s/8Mdx%umy>:", -100889203, "\t", "M_,Rmx.$R4FjV", 331777273);
		/* 63 */ test_printf_silent("I,QN\rP\v\r8M%s#z.l/v&iNf%p+Q6etZ'r%x ~%pq %x4Xt2;>vmp\f%u/X.", "d2U;N j\nc\tG0y4-}|cW{\tp,HViD\vLmd\n|Q\t#}kp!\n<JdGh-)C=5\vN^{u'y]]'7]Ul~h#pVBh<m-{/e%Xf\nG 9m^Wh", (void *)7593076308988842631, 2119780553, (void *)1032555662812761258, -200015988, -1992298429);
		/* 64 */ test_printf_silent("_(uz63E$a\f%p%p-TUUiyJ%di%cu==6\f%%Xq\"e;%x#{]<%cNf=l%iH!0X7_5Y%pA?p%iM,Wr'Z\\N", (void *)9071298117195693593, (void *)-2799438006765431272, 403189446, -487470026, 1969157775, -2071605728, 1252509416, (void *)-2129171911660803981, 1224954296);
		/* 65 */ test_printf_silent("w$K'|l%x\"/Nf%d\vn<pj`g#p%%t-~GVC?%i}LRn$FE<W ", -102774938, 620628598, -679355475);
		/* 66 */ test_printf_silent("b7\r)\"7H\r?J%cFp)B/%c!.-@%c]6+{$%d+,UtND%xyWDm#%uM{1K$Fe\v;Q%d}%c4g%x|(Z(et\r'^r%s,[3nMt@c", 509483457, 338884944, 1301820670, -389618492, -2097153543, -1927101661, -762097061, 787768780, -1052000206, "~f)%P`>T^z~\vRXYg2UWgRQ-G `k;qcYl;}?vr#{/2}e}}J;\nXOJ{k'J0ZaW`@3hlc}8O@/MfGO");
		/* 67 */ test_printf_silent("V-R~5%d2>D,T5%p2%c^Z5\tp#mN*%i)tR0%cF#\nYg*%u vgKe@M %%S", -502440828, (void *)-8184483873208968517, 1844794329, 1793263112, -702446208, 511956066);
		/* 68 */ test_printf_silent("d-%u<\nkE8`|A\\%sS5?l5P'", -1154494812, "{p_h5^C3e)rhU/2QWYdS:\\C");
		/* 69 */ test_printf_silent("%s%cY6%dDo>BS%pvb-M\r\rk1.Y%p%Xn3-5U T*%iS", "\\+3r&/gT<Y@R2v>*I|{V%slF{U=g/.$MIj7CJF8", -480451101, 1113214903, (void *)5334845133042486092, (void *)-6051315281803390353, 579030097, -1776644557);
		/* 70 */ test_printf_silent("!izagvV%xL%XOh*Z(@f%dRBCN%cj&KS;%xm x\\M-t?%dP%s8gTwqt?=H", -983100950, -1980093909, 842206081, 1673467691, 1803004879, -285531876, "I`'Ys3C(bE\\/ RD<B.{q6cV$6AMB]hSU<MF;CG8f/5qC<6K");
		/* 71 */ test_printf_silent("h~2y]K6b\f>%cE%p*:g%i%xkdL}6", -1715776114, (void *)-6634801199935291870, -346010180, 307588);
		/* 72 */ test_printf_silent("([3,lXhE%x0XO6&2%x0c+l:Jw)\fL%x", -274416923, -516084005, 1004778911);
		/* 73 */ test_printf_silent("%cUwr-y%%%%\noGi+)do%X>=W.b%XULl7N%p,-j69%sc+%Xv|LL", 2015898184, -630439270, 814019942, (void *)-3872291747177107693, "-y.!", -1514172691);
		/* 74 */ test_printf_silent("SB%dL<m_eA%p$;\t!Z@,1C%iVAq(VAWMU%ck3kz", 1031807910, (void *)2771394519615643363, 76240039, -1756731753);
		/* 75 */ test_printf_silent("c' %d2%ps8JHC}_h8E%iyu\trAj{%if7X%X%idP3%c\n%psMon6", 213848672, (void *)-8402629105723954438, -1016444369, 37806098, 1829677369, -1403182290, -1584893934, (void *)3917423172689121775);
		/* 76 */ test_printf_silent("&\t%i+/ qc!fq%ibf'dZL+Wz%c%XC P]&]%i5r!]A##Z::%s", -1161364586, 2035368860, -237509385, 1882367696, 1586005872, "a!aG\f*hGh'HYU9PbKA\rKN_Swf\"aM*=&9}L1h64s{pp7`>u[DVZ$`KBUN/X0h\r6_Xll\\;Iawd\v/J~\t\fn7a#");
		/* 77 */ test_printf_silent("(\nG'8Y5%Xfk#yP%cee`oOM%%JY\n<Bxpr~5%%|mHC&Im.", -880827441, 61873008);
		/* 78 */ test_printf_silent("5DA?@<%d<}aYZg{%u#YR%i44u {\rjW_0%x\\<.Pg%pc&/EH@%cC,{+{\ff%uT#", 1794822532, -61223700, 1485671047, -1678940640, (void *)4441949261150993511, -1071965418, -34871285);
		/* 79 */ test_printf_silent("{-iW&,(2/Q%p%x$st%%|aY4HF7vrX%s_6h|%ps3qg} sm%s1\r", (void *)-2958791194343315703, -961837757, "QCe28,C6E/W\\C\fqVxNG?$ceS(;&F'J\"wZ&J", (void *)-8726339865677279731, "{zd@Dve!S1:C`$.kvem4$Lh|3N='56");
		/* 80 */ test_printf_silent("\rvWB>I$3%XJJg1 FoN\\b%po2`?W9W%uy%i1_!354{%iL{%dmE|W^=h", -1455481007, (void *)4927389003719528593, 1203200197, -354874328, -1744399634, -500951182);
		/* 81 */ test_printf_silent("AA|9yA$%XpI:QI'%s(qG%xC_\v\n%c\f!z}kn%c2'yw[j", -1452648536, "e}%wU!3nl}S>v$lO|Y$.crUfc`d", 1933430085, 529712254, 1085305097);
		/* 82 */ test_printf_silent("*c[`4R%i%pz%x1oC%d~9rs'%%%u@4+aMct3n%xs\n{{JWa8a%Xq%c%%}6XK2", -2144193278, (void *)-7663822753739698712, -848116086, 1051672931, 340054249, -210162001, 1624686694, -2113251185);
		/* 83 */ test_printf_silent("s*~Fg%ur\fl8(Q`b%s%i\r!@wb%%2LXXnnq\\zU%uXXw]P/g%s=M71_,q", 1505293958, "(%1=Pdly82PR2;Y3BUR/}VYD^+)}+QO[V*Tb'0u<uWrzL\n4JWiCs\nLiyDqn\fcj>F7P-hb6*S \r\\l~8isl:?[MgtzW)-;EdKGK", 1738041259, 1029208019, "=du\v+<Jn\vA6\")ifFMV;t6>he\nn7'T,.+!RzD{taGD`3K\r.?.pmo>wg");
		/* 84 */ test_printf_silent("zcY(![T%p <YqSg\v/%i2kF%ufh{", (void *)7000886938361532441, -106429559, -1940495938);
		/* 85 */ test_printf_silent("P#YZByk%X5SR<?`\fBV%u=97|h%p!%uqLY)%u~.%c\v,\\, 'ch%u@Tdk%p95]%i;+^R?$K[%p\f:0/9I*", 490816514, 124950254, (void *)-9069160124406216825, -1597299146, 1690518929, -1154197671, 1056433521, (void *)4203568183281204896, 1954024448, (void *)1138075505283249637);
		/* 86 */ test_printf_silent("P_.e%c.w&Cu{%%,|1Q:%%qQKB:k )f%cv:%sD1o)y%c3~K*%X<zj\foEP^q%u}tw%x#O5 D9%%E", -1374287767, 1818955450, "Ov\rZ?$n2@j(GxH6RTT1", 930108335, 1491601754, -1321103183, 1892264579);
		/* 87 */ test_printf_silent("w~OI8%i<\r@pe7%X~Pav70&Z'%uyU]\")\t/{%XjsG/!tRnPh%i|sr5a\rW#\"-%X@_,q_U?-]d%sR1}%x7D%u|Qv\noS%p", -1285151909, 1163146467, 398209371, -1472929366, 487887511, -91444493, "@e|eig!3W\f5kRrC7sNd,kaD+BoL=,RTr]wB9z\r^Ab?_\\i!'M ", 1397029935, -753349478, (void *)7276852936664151858);
		/* 88 */ test_printf_silent("0`zp%s*fF)2K1:_%pb\v4\n%u0%uE_oh+-_3%s\"\n \t%sJR,i/ynzs%ip4y#l<^M^@", "fUV0E!Gg\r\"cZD/2qG@\t'`aDEc#]:w\"w&lT!`", (void *)-8749170071718481913, 789008615, 278788253, "(IJxiLx#<-)'5L#r7>h \"K e4)", "g'R?a<HWCkZ\n1xAPzOW!v|EGPKxv$gHTr*=5+\n\t]hqw`#\\:Wg&|Zi\t!:0sPgyF],dHZnJ|RbbPbx?+jS(lhRJZ1:kS", -1140324651);
		/* 89 */ test_printf_silent("\t%s\n%ir4tsLqzhk%p\"l*8w{QW%iHYA%ic", "bQbDX W}}l Q#H]B#<K}EV", 1306332326, (void *)1937001806846809036, 539365706, 626373159);
		/* 90 */ test_printf_silent("f\t^qVY\"%dQ;ud,PQX^%X%c-i8j1%x%cp`-S>2%X%p%%/(\n%p^w(y')=`7i", -162909182, 1577588399, 1951238977, 2125677240, -1694243263, -307439752, (void *)-1725399923496421777, (void *)-7156842141753998703);
		/* 91 */ test_printf_silent("fDp\t5V|Da\t%s%d\n`%%t", "'n[n+s\ta ])AjRN!oo\" \\\vI/cz3m/x^QT\tIE9`tQdxm.>{,)\n|lc", -1774129357);
		/* 92 */ test_printf_silent("(\\zj6:\\Klk%x)R;CF|?q%XiW7+%cF=/WvM%Xzqafvk%cJY", -93549767, 2113172043, 37416016, 218681895, -69107240);
		/* 93 */ test_printf_silent("XJ&dF0%sB>[i/%cE%i%ubvR*\"um\n5%%iI%X~+Zk{`x 9I%sH:,J\"#@{%p\fu1hDE\vU*%p>,qu%x-px28EWr-", "QQ93PSmpin+onyZ$()mk<5q\n>ysyt\rvB4A$^B7q6cRY5(_n\n83pQYP4Qp\nv", -227050077, -562379859, -2106119476, -1190437144, "fV/+z )uX>lNRAgk:;$(kH\t=8w!8C[Q{-=\vqN$3\ruf?_`rl]6TeE-z{\n^$Up~1-^Io}P6)i>KL'$lH\vMW<^:|+ \\<)", (void *)-2276031491788362480, (void *)-3062095595129860541, 740403626);
		/* 94 */ test_printf_silent("4w7(\n%ce'%cN^4K%x\fX$zr%c%sB|{w/LD{S%%%%svig8U_T{%sMXBK\ra+;%X|%X", 616749404, -244741920, 510339379, -205170343, "\v=mxT@$", "\rpR:WQD,f0t0;F& /8>\r~A_\n\nbu|S3;MHX7j^", 44265507, -1316542226);
		/* 95 */ test_printf_silent("N5x>p%pyX< !%iW\\g7Wm(7F%dY@*==[%de@%%fu t", (void *)2086149615510264305, -1286725966, -1539115899, 1313581152);
		/* 96 */ test_printf_silent("\vt4%d>o%p%iC#%dDB1 %dXW~N(,^\f", 210671596, (void *)1969728398881581354, 1221605399, -1205850662, 1503063862);
		/* 97 */ test_printf_silent("Ou3$%iYUHYc%sO:6JQ%sP)-,Sjs]*\f%x4JwZz@%c&Pd/T=", -628582726, "|\n.{'Due0@Xtse\\1Fj4>a\" LfqRkQ6h)ansn` |h:'\tnza8K\vONr\fI)bKJV~\fzE1\rxwNV!6o.w:\ffEJ", "E4luX+R\r<LO5hlo@5B\n$TkcE_Kqt\f,[Wnd2,hm&qp&V= 39<N8A;zQg\nzA*87G$fC", -1591344991, 1819929075);
		/* 98 */ test_printf_silent("/|%X\rq3OqILNf%sr%s~>e3\rJ%iy5,Rr9Si)\"%x8DNGn-z", -1016973324, "D4Ha_\f\n:\v;/|\reN\\\\o{[X7E{C\r^:>@'(M\t*:0e\v&MoLCD", "v8ar[p837QlU'", 15481479, -1579933184);
		/* 99 */ test_printf_silent("c!ltNLK,%u( _2g%pjs\vM`v%p,Y ZiR%s+oI,}D#NA", 1365770437, (void *)8610351226391146838, (void *)760087325389414209, "Ehl\v@Op)1#rR+");
		/* 100 */ test_printf_silent("z\t0u\f%i_,8'nA%s]X{uyO%X9EMSA.U*jc%cA&G0;XAKRD%ucny4%p-9D9tAgS", 870311911, "e:!*e82}UY{eLO*?Qg-1yhr1e$=?/7gG1Ji\",p_3\\a\v{\n2-al$+<p@.^", -1118194341, -2059326640, 937670032, (void *)3647809265735195822);
		/* 101 */ test_printf("XW9V?(;d%u%c#!,'m+is~%c*:LI8+@u %ph", 659456062, 439068653, -801240496, (void *)-6189198088243159451);
	});
}