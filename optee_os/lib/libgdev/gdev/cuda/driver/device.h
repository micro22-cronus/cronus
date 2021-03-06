/*
 * Copyright (C) 2011 Shinpei Kato
 * Copyright (C) 2013 AXE, Inc.
 *
 * Systems Research Lab, University of California at Santa Cruz
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

struct device_properties {
    int id;
    char *name;
    int mp_count;
    int bus_width;
    int l2_cache;
    int ecc;
};

/*
 * The PCI id list and hardware features can be found at
 * https://envytools.readthedocs.io/en/latest/hw/pciid.html
 * https://en.wikipedia.org/wiki/List_of_Nvidia_graphics_processing_units
 */

static struct device_properties device_list[] = {
    {0x0191, "NVIDIA GeForce 8800 GTX",		0,	0,	0,	},
    {0x0193, "NVIDIA GeForce 8800 GTS",		0,	0,	0,	},
    {0x0194, "NVIDIA GeForce 8800 Ultra",	0,	0,	0,	},
    {0x019D, "NVIDIA Quadro FX 5600",		0,	0,	0,	},
    {0x019E, "NVIDIA Quadro FX 4600",		0,	0,	0,	},
    {0x0400, "NVIDIA GeForce 8600 GTS",		0,	0,	0,	},
    {0x0401, "NVIDIA GeForce 8600 GT",		0,	0,	0,	},
    {0x0402, "NVIDIA GeForce 8600 GT ",		0,	0,	0,	},
    {0x0403, "NVIDIA GeForce 8600 GS",		0,	0,	0,	},
    {0x0404, "NVIDIA GeForce 8400 GS",		0,	0,	0,	},
    {0x0405, "NVIDIA GeForce 9500M GS",		0,	0,	0,	},
    {0x0406, "NVIDIA GeForce 8300 GS",		0,	0,	0,	},
    {0x0407, "NVIDIA GeForce 8600M GT",		0,	0,	0,	},
    {0x0408, "NVIDIA GeForce 9650M GS",		0,	0,	0,	},
    {0x0409, "NVIDIA GeForce 8700M GT",		0,	0,	0,	},
    {0x040A, "NVIDIA Quadro FX 370",		0,	0,	0,	},
    {0x040B, "NVIDIA Quadro NVS 320M",		0,	0,	0,	},
    {0x040C, "NVIDIA Quadro FX 570M",		0,	0,	0,	},
    {0x040D, "NVIDIA Quadro FX 1600M",		0,	0,	0,	},
    {0x040E, "NVIDIA Quadro FX 570",		0,	0,	0,	},
    {0x040F, "NVIDIA Quadro FX 1700",		0,	0,	0,	},
    {0x0410, "NVIDIA GeForce GT 330",		0,	0,	0,	},
    {0x0420, "NVIDIA GeForce 8400 SE",		0,	0,	0,	},
    {0x0421, "NVIDIA GeForce 8500 GT",		0,	0,	0,	},
    {0x0422, "NVIDIA GeForce 8400 GS ",		0,	0,	0,	},
    {0x0423, "NVIDIA GeForce 8300 GS ",		0,	0,	0,	},
    {0x0424, "NVIDIA GeForce 8400 GS  ",	0,	0,	0,	},
    {0x0425, "NVIDIA GeForce 8600M GS",		0,	0,	0,	},
    {0x0426, "NVIDIA GeForce 8400M GT",		0,	0,	0,	},
    {0x0427, "NVIDIA GeForce 8400M GS",		0,	0,	0,	},
    {0x0428, "NVIDIA GeForce 8400M G",		0,	0,	0,	},
    {0x0429, "NVIDIA Quadro NVS 140M",		0,	0,	0,	},
    {0x042A, "NVIDIA Quadro NVS 130M",		0,	0,	0,	},
    {0x042B, "NVIDIA Quadro NVS 135M",		0,	0,	0,	},
    {0x042C, "NVIDIA GeForce 9400 GT",		0,	0,	0,	},
    {0x042D, "NVIDIA Quadro FX 360M",		0,	0,	0,	},
    {0x042E, "NVIDIA GeForce 9300M G",		0,	0,	0,	},
    {0x042F, "NVIDIA Quadro NVS 290",		0,	0,	0,	},
    {0x05E0, "NVIDIA GeForce GTX 295",		0,	0,	0,	},
    {0x05E1, "NVIDIA GeForce GTX 280",		0,	0,	0,	},
    {0x05E2, "NVIDIA GeForce GTX 260",		0,	0,	0,	},
    {0x05E3, "NVIDIA GeForce GTX 285",		0,	0,	0,	},
    {0x05E6, "NVIDIA GeForce GTX 275",		0,	0,	0,	},
    {0x05EA, "NVIDIA GeForce GTX 260 ",		0,	0,	0,	},
    {0x05EB, "NVIDIA GeForce GTX 295 ",		0,	0,	0,	},
    {0x05F9, "NVIDIA Quadro CX",		0,	0,	0,	},
    {0x05FD, "NVIDIA Quadro FX 5800",		0,	0,	0,	},
    {0x05FE, "NVIDIA Quadro FX 4800",		0,	0,	0,	},
    {0x05FF, "NVIDIA Quadro FX 3800",		0,	0,	0,	},
    {0x0600, "NVIDIA GeForce 8800 GTS 512",	0,	0,	0,	},
    {0x0601, "NVIDIA GeForce 9800 GT",		0,	0,	0,	},
    {0x0602, "NVIDIA GeForce 8800 GT",		0,	0,	0,	},
    {0x0603, "NVIDIA GeForce GT 230",		0,	0,	0,	},
    {0x0604, "NVIDIA GeForce 9800 GX2",		0,	0,	0,	},
    {0x0605, "NVIDIA GeForce 9800 GT ",		0,	0,	0,	},
    {0x0606, "NVIDIA GeForce 8800 GS",		0,	0,	0,	},
    {0x0607, "NVIDIA GeForce GTS 240",		0,	0,	0,	},
    {0x0608, "NVIDIA GeForce 9800M GTX",	0,	0,	0,	},
    {0x0609, "NVIDIA GeForce 8800M GTS",	0,	0,	0,	},
    {0x060A, "NVIDIA GeForce GTX 280M",		0,	0,	0,	},
    {0x060B, "NVIDIA GeForce 9800M GT",		0,	0,	0,	},
    {0x060C, "NVIDIA GeForce 8800M GTX",	0,	0,	0,	},
    {0x060F, "NVIDIA GeForce GTX 285M",		0,	0,	0,	},
    {0x0610, "NVIDIA GeForce 9600 GSO",		0,	0,	0,	},
    {0x0611, "NVIDIA GeForce 8800 GT ",		0,	0,	0,	},
    {0x0612, "NVIDIA GeForce 9800 GTX/9800 GTX+",0,	0,	0,	},
    {0x0613, "NVIDIA GeForce 9800 GTX+",	0,	0,	0,	},
    {0x0614, "NVIDIA GeForce 9800 GT  ",	0,	0,	0,	},
    {0x0615, "NVIDIA GeForce GTS 250",		0,	0,	0,	},
    {0x0617, "NVIDIA GeForce 9800M GTX",	0,	0,	0,	},
    {0x0618, "NVIDIA GeForce GTX 260M",		0,	0,	0,	},
    {0x0619, "NVIDIA Quadro FX 4700 X2",	0,	0,	0,	},
    {0x061A, "NVIDIA Quadro FX 3700",		0,	0,	0,	},
    {0x061B, "NVIDIA Quadro VX 200",		0,	0,	0,	},
    {0x061C, "NVIDIA Quadro FX 3600M",		0,	0,	0,	},
    {0x061D, "NVIDIA Quadro FX 2800M",		0,	0,	0,	},
    {0x061E, "NVIDIA Quadro FX 3700M",		0,	0,	0,	},
    {0x061F, "NVIDIA Quadro FX 3800M",		0,	0,	0,	},
    {0x0621, "NVIDIA GeForce GT 230 ",		0,	0,	0,	},
    {0x0622, "NVIDIA GeForce 9600 GT",		0,	0,	0,	},
    {0x0623, "NVIDIA GeForce 9600 GS",		0,	0,	0,	},
    {0x0625, "NVIDIA GeForce 9600 GSO 512",	0,	0,	0,	},
    {0x0626, "NVIDIA GeForce GT 130",		0,	0,	0,	},
    {0x0627, "NVIDIA GeForce GT 140",		0,	0,	0,	},
    {0x0628, "NVIDIA GeForce 9800M GTS",	0,	0,	0,	},
    {0x062A, "NVIDIA GeForce 9700M GTS",	0,	0,	0,	},
    {0x062B, "NVIDIA GeForce 9800M GS",		0,	0,	0,	},
    {0x062C, "NVIDIA GeForce 9800M GTS  ",	0,	0,	0,	},
    {0x062D, "NVIDIA GeForce 9600 GT ",		0,	0,	0,	},
    {0x062E, "NVIDIA GeForce 9600 GT  ",	0,	0,	0,	},
    {0x0631, "NVIDIA GeForce GTS 160M",		0,	0,	0,	},
    {0x0635, "NVIDIA GeForce 9600 GSO ",	0,	0,	0,	},
    {0x0637, "NVIDIA GeForce 9600 GT   ",	0,	0,	0,	},
    {0x0638, "NVIDIA Quadro FX 1800",		0,	0,	0,	},
    {0x063A, "NVIDIA Quadro FX 2700M",		0,	0,	0,	},
    {0x0640, "NVIDIA GeForce 9500 GT",		0,	0,	0,	},
    {0x0641, "NVIDIA GeForce 9400 GT ",		0,	0,	0,	},
    {0x0643, "NVIDIA GeForce 9500 GT ",		0,	0,	0,	},
    {0x0644, "NVIDIA GeForce 9500 GS",		0,	0,	0,	},
    {0x0645, "NVIDIA GeForce 9500 GS ",		0,	0,	0,	},
    {0x0646, "NVIDIA GeForce GT 120",		0,	0,	0,	},
    {0x0647, "NVIDIA GeForce 9600M GT",		0,	0,	0,	},
    {0x0648, "NVIDIA GeForce 9600M GS",		0,	0,	0,	},
    {0x0649, "NVIDIA GeForce 9600M GT",		0,	0,	0,	},
    {0x064A, "NVIDIA GeForce 9700M GT",		0,	0,	0,	},
    {0x064B, "NVIDIA GeForce 9500M G",		0,	0,	0,	},
    {0x064C, "NVIDIA GeForce 9650M GT",		0,	0,	0,	},
    {0x0651, "NVIDIA GeForce G 110M",		0,	0,	0,	},
    {0x0652, "NVIDIA GeForce GT 130M",		0,	0,	0,	},
    {0x0653, "NVIDIA GeForce GT 120M",		0,	0,	0,	},
    {0x0654, "NVIDIA GeForce GT 320M",		0,	0,	0,	},
    {0x0655, "NVIDIA GeForce GT 120 ",		0,	0,	0,	},
    {0x0656, "NVIDIA GeForce GT 120  ",		0,	0,	0,	},
    {0x0658, "NVIDIA Quadro FX 380",		0,	0,	0,	},
    {0x0659, "NVIDIA Quadro FX 580",		0,	0,	0,	},
    {0x065A, "NVIDIA Quadro FX 1700M",		0,	0,	0,	},
    {0x065B, "NVIDIA GeForce 9400 GT  ",	0,	0,	0,	},
    {0x065C, "NVIDIA Quadro FX 770M",		0,	0,	0,	},
    {0x065F, "NVIDIA GeForce G210",		0,	0,	0,	},
    {0x06C0, "NVIDIA GeForce GTX 480",		15,	384,	786432,	},
    {0x06C4, "NVIDIA GeForce GTX 465",		11,	256,	0,	},
    {0x06CA, "NVIDIA GeForce GTX 480M",		0,	0,	0,	},
    {0x06CD, "NVIDIA GeForce GTX 470",		14,	320,	0,	},
    {0x06D8, "NVIDIA Quadro 6000",		0,	0,	0,	},
    {0x06D9, "NVIDIA Quadro 5000",		0,	0,	0,	},
    {0x06DA, "NVIDIA Quadro 5000M",		0,	0,	0,	},
    {0x06DC, "NVIDIA Quadro 6000  ",		0,	0,	0,	},
    {0x06DD, "NVIDIA Quadro 4000",		0,	0,	0,	},
    {0x06E0, "NVIDIA GeForce 9300 GE",		0,	0,	0,	},
    {0x06E1, "NVIDIA GeForce 9300 GS",		0,	0,	0,	},
    {0x06E2, "NVIDIA GeForce 8400",		0,	0,	0,	},
    {0x06E3, "NVIDIA GeForce 8400 SE ",		0,	0,	0,	},
    {0x06E4, "NVIDIA GeForce 8400 GS    ",	0,	0,	0,	},
    {0x06E6, "NVIDIA GeForce G100",		0,	0,	0,	},
    {0x06E7, "NVIDIA GeForce 9300 SE",		0,	0,	0,	},
    {0x06E8, "NVIDIA GeForce 9200M GS",		0,	0,	0,	},
    {0x06E9, "NVIDIA GeForce 9300M GS",		0,	0,	0,	},
    {0x06EA, "NVIDIA Quadro NVS 150M",		0,	0,	0,	},
    {0x06EB, "NVIDIA Quadro NVS 160M",		0,	0,	0,	},
    {0x06EC, "NVIDIA GeForce G 105M",		0,	0,	0,	},
    {0x06EF, "NVIDIA GeForce G 103M",		0,	0,	0,	},
    {0x06F1, "NVIDIA GeForce G105M",		0,	0,	0,	},
    {0x06F8, "NVIDIA Quadro NVS 420",		0,	0,	0,	},
    {0x06F9, "NVIDIA Quadro FX 370 LP",		0,	0,	0,	},
    {0x06FA, "NVIDIA Quadro NVS 450",		0,	0,	0,	},
    {0x06FB, "NVIDIA Quadro FX 370M",		0,	0,	0,	},
    {0x06FD, "NVIDIA Quadro NVS 295",		0,	0,	0,	},
    {0x06FF, "NVIDIA HICx16 + Graphics",	0,	0,	0,	},
    {0x0840, "NVIDIA GeForce 8200M",		0,	0,	0,	},
    {0x0844, "NVIDIA GeForce 9100M G",		0,	0,	0,	},
    {0x0845, "NVIDIA GeForce 8200M G",		0,	0,	0,	},
    {0x0846, "NVIDIA GeForce 9200 ",		0,	0,	0,	},
    {0x0847, "NVIDIA GeForce 9100",		0,	0,	0,	},
    {0x0848, "NVIDIA GeForce 8300",		0,	0,	0,	},
    {0x0849, "NVIDIA GeForce 8200",		0,	0,	0,	},
    {0x084A, "NVIDIA nForce 730a",		0,	0,	0,	},
    {0x084B, "NVIDIA GeForce 9200  ",		0,	0,	0,	},
    {0x084C, "NVIDIA nForce 980a/780a SLI",	0,	0,	0,	},
    {0x084D, "NVIDIA nForce 750a SLI",		0,	0,	0,	},
    {0x084F, "NVIDIA GeForce 8100 / nForce 720a",0,	0,	0,	},
    {0x0860, "NVIDIA GeForce 9400",		0,	0,	0,	},
    {0x0861, "NVIDIA GeForce 9400 ",		0,	0,	0,	},
    {0x0862, "NVIDIA GeForce 9400M G",		0,	0,	0,	},
    {0x0863, "NVIDIA GeForce 9400M",		0,	0,	0,	},
    {0x0864, "NVIDIA GeForce 9300",		0,	0,	0,	},
    {0x0865, "NVIDIA ION    ",			0,	0,	0,	},
    {0x0866, "NVIDIA GeForce 9400M G",		0,	0,	0,	},
    {0x0867, "NVIDIA GeForce 9400 ",		0,	0,	0,	},
    {0x0868, "NVIDIA nForce 760i SLI",		0,	0,	0,	},
    {0x0869, "NVIDIA GeForce 9400  ",		0,	0,	0,	},
    {0x086A, "NVIDIA GeForce 9400   ",		0,	0,	0,	},
    {0x086C, "NVIDIA GeForce 9300 / nForce 730i",0,	0,	0,	},
    {0x086D, "NVIDIA GeForce 9200   ",		0,	0,	0,	},
    {0x086E, "NVIDIA GeForce 9100M G",		0,	0,	0,	},
    {0x086F, "NVIDIA GeForce 8200M G",		0,	0,	0,	},
    {0x0870, "NVIDIA GeForce 9400M        ",	0,	0,	0,	},
    {0x0871, "NVIDIA GeForce 9200    ",		0,	0,	0,	},
    {0x0872, "NVIDIA GeForce G102M",		0,	0,	0,	},
    {0x0873, "NVIDIA GeForce G102M   ",		0,	0,	0,	},
    {0x0874, "NVIDIA ION     ",			0,	0,	0,	},
    {0x0876, "NVIDIA ION",			0,	0,	0,	},
    {0x087A, "NVIDIA GeForce 9400    ",		0,	0,	0,	},
    {0x087D, "NVIDIA ION      ",		0,	0,	0,	},
    {0x087E, "NVIDIA ION LE",			0,	0,	0,	},
    {0x087F, "NVIDIA ION LE ",			0,	0,	0,	},
    {0x08A0, "NVIDIA GeForce 320M",		0,	0,	0,	},
    {0x08A2, "NVIDIA GeForce 320M  ",		0,	0,	0,	},
    {0x08A3, "NVIDIA GeForce 320M   ",		0,	0,	0,	},
    {0x08A4, "NVIDIA GeForce 320M    ",		0,	0,	0,	},
    {0x0A20, "NVIDIA GeForce GT 220 ",		0,	0,	0,	},
    {0x0A22, "NVIDIA GeForce 315",		0,	0,	0,	},
    {0x0A23, "NVIDIA GeForce 210",		0,	0,	0,	},
    {0x0A26, "NVIDIA GeForce 405",		0,	0,	0,	},
    {0x0A27, "NVIDIA GeForce 405 ",		0,	0,	0,	},
    {0x0A28, "NVIDIA GeForce GT 230M",		0,	0,	0,	},
    {0x0A29, "NVIDIA GeForce GT 330M",		0,	0,	0,	},
    {0x0A2A, "NVIDIA GeForce GT 230M",		0,	0,	0,	},
    {0x0A2B, "NVIDIA GeForce GT 330M ",		0,	0,	0,	},
    {0x0A2C, "NVIDIA NVS 5100M",		0,	0,	0,	},
    {0x0A2D, "NVIDIA GeForce GT 320M",		0,	0,	0,	},
    {0x0A32, "NVIDIA GeForce GT 415",		0,	0,	0,	},
    {0x0A34, "NVIDIA GeForce GT 240M",		0,	0,	0,	},
    {0x0A35, "NVIDIA GeForce GT 325M",		0,	0,	0,	},
    {0x0A38, "NVIDIA Quadro 400",		0,	0,	0,	},
    {0x0A3C, "NVIDIA Quadro FX 880M",		0,	0,	0,	},
    {0x0A60, "NVIDIA GeForce G210 ",		0,	0,	0,	},
    {0x0A62, "NVIDIA GeForce 205",		0,	0,	0,	},
    {0x0A63, "NVIDIA GeForce 310",		0,	0,	0,	},
    {0x0A64, "NVIDIA ION ",			0,	0,	0,	},
    {0x0A65, "NVIDIA GeForce 210 ",		0,	0,	0,	},
    {0x0A66, "NVIDIA GeForce 310 ",		0,	0,	0,	},
    {0x0A67, "NVIDIA GeForce 315 ",		0,	0,	0,	},
    {0x0A68, "NVIDIA GeForce G105M",		0,	0,	0,	},
    {0x0A69, "NVIDIA GeForce G105M",		0,	0,	0,	},
    {0x0A6A, "NVIDIA NVS 2100M",		0,	0,	0,	},
    {0x0A6C, "NVIDIA NVS 3100M",		0,	0,	0,	},
    {0x0A6E, "NVIDIA GeForce 305M",		0,	0,	0,	},
    {0x0A6F, "NVIDIA ION  ",			0,	0,	0,	},
    {0x0A70, "NVIDIA GeForce 310M",		0,	0,	0,	},
    {0x0A71, "NVIDIA GeForce 305M",		0,	0,	0,	},
    {0x0A72, "NVIDIA GeForce 310M           ",	0,	0,	0,	},
    {0x0A73, "NVIDIA GeForce 305M ",		0,	0,	0,	},
    {0x0A74, "NVIDIA GeForce G210M",		0,	0,	0,	},
    {0x0A75, "NVIDIA GeForce 310M               ",0,	0,	0,	},
    {0x0A76, "NVIDIA ION    ",			0,	0,	0,	},
    {0x0A78, "NVIDIA Quadro FX 380 LP",		0,	0,	0,	},
    {0x0A7A, "NVIDIA GeForce 405",		0,	0,	0,	},
    {0x0A7C, "NVIDIA Quadro FX 380M",		0,	0,	0,	},
    {0x0CA0, "NVIDIA GeForce GT 330 ",		0,	0,	0,	},
    {0x0CA2, "NVIDIA GeForce GT 320",		0,	0,	0,	},
    {0x0CA3, "NVIDIA GeForce GT 240",		0,	0,	0,	},
    {0x0CA4, "NVIDIA GeForce GT 340",		0,	0,	0,	},
    {0x0CA5, "NVIDIA GeForce GT 220  ",		0,	0,	0,	},
    {0x0CA7, "NVIDIA GeForce GT 330  ",		0,	0,	0,	},
    {0x0CA9, "NVIDIA GeForce GTS 250M",		0,	0,	0,	},
    {0x0CAC, "NVIDIA GeForce GT 220   ",	0,	0,	0,	},
    {0x0CAF, "NVIDIA GeForce GT 335M",		0,	0,	0,	},
    {0x0CB0, "NVIDIA GeForce GTS 350M",		0,	0,	0,	},
    {0x0CB1, "NVIDIA GeForce GTS 360M",		0,	0,	0,	},
    {0x0CBC, "NVIDIA Quadro FX 1800M",		0,	0,	0,	},
    {0x0DC0, "NVIDIA GeForce GT 440",		0,	0,	0,	},
    {0x0DC4, "NVIDIA GeForce GTS 450",		4,	128,	262144,	},
    {0x0DC5, "NVIDIA GeForce GTS 450 ",		3,	192,	0,	},
    {0x0DC6, "NVIDIA GeForce GTS 450  ",	4,	128,	262144,	},
    {0x0DCD, "NVIDIA GeForce GT 555M",		0,	0,	0,	},
    {0x0DCE, "NVIDIA GeForce GT 555M",		0,	0,	0,	},
    {0x0DD1, "NVIDIA GeForce GTX 460M",		0,	0,	0,	},
    {0x0DD2, "NVIDIA GeForce GT 445M",		0,	0,	0,	},
    {0x0DD3, "NVIDIA GeForce GT 435M ",		0,	0,	0,	},
    {0x0DD6, "NVIDIA GeForce GT 550M  ",	0,	0,	0,	},
    {0x0DD8, "NVIDIA Quadro 2000",		0,	0,	0,	},
    {0x0DDA, "NVIDIA Quadro 2000M ",		0,	0,	0,	},
    {0x0DE0, "NVIDIA GeForce GT 440 ",		2,	128,	0,	},
    {0x0DE1, "NVIDIA GeForce GT 430",		2,	128,	0,	},
    {0x0DE2, "NVIDIA GeForce GT 420",		1,	128,	0,	},
    {0x0DE3, "NVIDIA GeForce GT 635M ",		0,	0,	0,	},
    {0x0DE4, "NVIDIA GeForce GT 520",		1,	64,	0,	},
    {0x0DE5, "NVIDIA GeForce GT 530",		2,	128,	0,	},
    {0x0DE8, "NVIDIA GeForce GT 620M",		0,	0,	0,	},
    {0x0DE9, "NVIDIA GeForce GT 630M",		0,	0,	0,	},
    {0x0DEA, "NVIDIA GeForce 610M",		0,	0,	0,	},
    {0x0DEB, "NVIDIA GeForce GT 555M",		0,	0,	0,	},
    {0x0DEC, "NVIDIA GeForce GT 525M",		0,	0,	0,	},
    {0x0DED, "NVIDIA GeForce GT 520M",		0,	0,	0,	},
    {0x0DEE, "NVIDIA GeForce GT 415M",		0,	0,	0,	},
    {0x0DEF, "NVIDIA NVS 5400M ",		0,	0,	0,	},
    {0x0DF0, "NVIDIA GeForce GT 425M",		0,	0,	0,	},
    {0x0DF1, "NVIDIA GeForce GT 420M",		0,	0,	0,	},
    {0x0DF2, "NVIDIA GeForce GT 435M",		0,	0,	0,	},
    {0x0DF3, "NVIDIA GeForce GT 420M ",		0,	0,	0,	},
    {0x0DF4, "NVIDIA GeForce GT 540M",		0,	0,	0,	},
    {0x0DF5, "NVIDIA GeForce GT 525M",		0,	0,	0,	},
    {0x0DF6, "NVIDIA GeForce GT 550M",		0,	0,	0,	},
    {0x0DF7, "NVIDIA GeForce GT 520M",		0,	0,	0,	},
    {0x0DF8, "NVIDIA Quadro 600",		0,	0,	0,	},
    {0x0DF9, "NVIDIA Quadro 500M",		0,	0,	0,	},
    {0x0DFA, "NVIDIA Quadro 1000M",		0,	0,	0,	},
    {0x0DFC, "NVIDIA NVS 5200M",		0,	0,	0,	},
    {0x0E22, "NVIDIA GeForce GTX 460",		7,	0,	0,	},
    {0x0E23, "NVIDIA GeForce GTX 460 SE",	6,	256,	0,	},
    {0x0E24, "NVIDIA GeForce GTX 460 ",		0,	0,	0,	},
    {0x0E30, "NVIDIA GeForce GTX 470M",		0,	0,	0,	},
    {0x0E31, "NVIDIA GeForce GTX 485M",		0,	0,	0,	},
    {0x0E3A, "NVIDIA Quadro 3000M",		0,	0,	0,	},
    {0x0E3B, "NVIDIA Quadro 4000M",		0,	0,	0,	},
    {0x0F00, "NVIDIA GeForce GT 630",		2,	128,	0,	},
    {0x0F01, "NVIDIA GeForce GT 620",		2,	64,	0,	},
    {0x0FC0, "NVIDIA GeForce GT 640",		2,	128,	262144,	},
    {0x0FC1, "NVIDIA GeForce GT 640 ",		2,	64,	0,	},
    {0x0FC2, "NVIDIA GeForce GT 630 ",		1,	128,	0,	},
    {0x0FC6, "NVIDIA GeForce GTX 650",		2,	128,	0,	},
    {0x0FD1, "NVIDIA GeForce GT 650M",		2,	128,	262144,	},
    {0x0FD2, "NVIDIA GeForce GT 640M",		0,	0,	0,	},
    {0x0FD3, "NVIDIA GeForce GT 640M LE",	0,	0,	0,	},
    {0x0FD4, "NVIDIA GeForce GTX 660M",		0,	0,	0,	},
    {0x0FD5, "NVIDIA GeForce GT 650M",		0,	0,	0,	},
    {0x0FD8, "NVIDIA GeForce GT 640M",		0,	0,	0,	},
    {0x0FD9, "NVIDIA GeForce GT 645M",		0,	0,	0,	},
    {0x0FE0, "NVIDIA GeForce GTX 660M",		0,	0,	0,	},
    {0x0FF9, "NVIDIA Quadro K2000D",		0,	0,	0,	},
    {0x0FFA, "NVIDIA Quadro K600",		0,	0,	0,	},
    {0x0FFB, "NVIDIA Quadro K2000M ",		0,	0,	0,	},
    {0x0FFC, "NVIDIA Quadro K1000M ",		0,	0,	0,	},
    {0x0FFD, "NVIDIA NVS 510",			0,	0,	0,	},
    {0x0FFE, "NVIDIA Quadro K2000",		0,	0,	0,	},
    {0x0FFF, "NVIDIA Quadro 410",		0,	0,	0,	},
    {0x1003, "NVIDIA GeForce GTX Titan LE",	0,	0,	0,	},
    {0x1004, "NVIDIA GeForce GTX 780",		12,	384,	1572864,},
    {0x1005, "NVIDIA GeForce GTX Titan",	14,	384,	0,	},
    {0x101f, "NVIDIA Tesla K20",		0,	0,	0,	},
    {0x1020, "NVIDIA Tesla K20X",		0,	0,	0,	},
    {0x1021, "NVIDIA Tesla K20Xm",		0,	0,	0,	},
    {0x1022, "NVIDIA Tesla K20c",		0,	0,	0,	},
    {0x1026, "NVIDIA Tesla K20s",		0,	0,	0,	},
    {0x1028, "NVIDIA Tesla K20m",		0,	0,	0,	},
    {0x1040, "NVIDIA GeForce GT 520 ",		1,	64,	0,	},
    {0x1042, "NVIDIA GeForce 510",		1,	64,	0,	},
    {0x1048, "NVIDIA GeForce 605",		1,	64,	0,	},
    {0x1049, "NVIDIA GeForce GT 620 ",		1,	64,	0,	},
    {0x104A, "NVIDIA GeForce GT 610",		1,	64,	65536,	},
    {0x1050, "NVIDIA GeForce GT 520M",		0,	0,	0,	},
    {0x1051, "NVIDIA GeForce GT 520MX",		0,	0,	0,	},
    {0x1052, "NVIDIA GeForce GT 520M      ",	0,	0,	0,	},
    {0x1054, "NVIDIA GeForce 410M",		0,	0,	0,	},
    {0x1055, "NVIDIA GeForce 410M",		0,	0,	0,	},
    {0x1056, "NVIDIA NVS 4200M",		0,	0,	0,	},
    {0x1057, "NVIDIA NVS 4200M ",		0,	0,	0,	},
    {0x1058, "NVIDIA GeForce 610M",		0,	0,	0,	},
    {0x1059, "NVIDIA GeForce 610M ",		0,	0,	0,	},
    {0x105A, "NVIDIA GeForce 610M       ",	0,	0,	0,	},
    {0x107D, "NVIDIA NVS 310",			0,	0,	0,	},
    {0x1080, "NVIDIA GeForce GTX 580",		16,	384,	786432,	},
    {0x1081, "NVIDIA GeForce GTX 570",		15,	320,	655360,	},
    {0x1082, "NVIDIA GeForce GTX 560 Ti",	11,	320,	0,	},
    {0x1084, "NVIDIA GeForce GTX 560",		12,	320,	0,	},
    {0x1086, "NVIDIA GeForce GTX 570 ",		15,	320,	655360,	},
    {0x1087, "NVIDIA GeForce GTX 560 Ti ",	14,	320,	0,	},
    {0x1088, "NVIDIA GeForce GTX 590",		32,	768,	1572864,},
    {0x1089, "NVIDIA GeForce GTX 580 ",		16,	384,	786432,	},
    {0x108B, "NVIDIA GeForce GTX 580  ",	16,	384,	786432,	},
    {0x109A, "NVIDIA Quadro 5010M ",		0,	0,	0,	},
    {0x109B, "NVIDIA Quadro 7000",		0,	0,	0,	},
    {0x10C0, "NVIDIA GeForce 9300 GS ",		0,	0,	0,	},
    {0x10C3, "NVIDIA GeForce 8400GS",		0,	0,	0,	},
    {0x10C5, "NVIDIA GeForce 405  ",		0,	0,	0,	},
    {0x10D8, "NVIDIA NVS 300",			0,	0,	0,	},
    {0x1140, "NVIDIA GeForce GT 620M        ",	0,	0,	0,	},
    {0x1180, "NVIDIA GeForce GTX 680",		8,	256,	524288,	},
    {0x1182, "NVIDIA GeForce GTX 760 Ti",	0,	0,	0,	},
    {0x1183, "NVIDIA GeForce GTX 660 Ti",	7,	192,	0,	},
    {0x1184, "NVIDIA GeForce GTX 770",		8,	256,	524288,	},
    {0x1185, "NVIDIA GeForce GTX 660",		6,	192,	0,	},
    {0x1187, "NVIDIA GeForce GTX 760",		6,	256,	0,	},
    {0x1188, "NVIDIA GeForce GTX 690",		16,	512,	1048576,},
    {0x1189, "NVIDIA GeForce GTX 670",		7,	256,	524288,	},
    {0x11A0, "NVIDIA GeForce GTX 680M",		0,	0,	0,	},
    {0x11A1, "NVIDIA GeForce GTX 670MX",	0,	0,	0,	},
    {0x11A2, "NVIDIA GeForce GTX 675MX",	0,	0,	0,	},
    {0x11A3, "NVIDIA GeForce GTX 680MX",	0,	0,	0,	},
    {0x11A7, "NVIDIA GeForce GTX 675MX",	0,	0,	0,	},
    {0x11BA, "NVIDIA Quadro K5000",		0,	0,	0,	},
    {0x11BC, "NVIDIA Quadro K5000M",		0,	0,	0,	},
    {0x11BD, "NVIDIA Quadro K4000M",		0,	0,	0,	},
    {0x11BE, "NVIDIA Quadro K3000M",		0,	0,	0,	},
    {0x11BF, "NVIDIA GRID K2",			0,	0,	0,	},
    {0x11C0, "NVIDIA GeForce GTX 660 ",		5,	192,	0,	},
    {0x11C2, "NVIDIA GeForce GTX 650 Ti ",	4,	192,	0,	},
    {0x11C3, "NVIDIA GeForce GTX 650 Ti ",	0,	0,	0,	},
    {0x11C4, "NVIDIA GeForce GTX 645 ",		3,	128,	0,	},
    {0x11C6, "NVIDIA GeForce GTX 650 Ti ",	4,	128,	0,	},
    {0x11FA, "NVIDIA Quadro K4000",		0,	0,	0,	},
    {0x1200, "NVIDIA GeForce GTX 560 Ti  ",	8,	256,	0,	},
    {0x1201, "NVIDIA GeForce GTX 560 ",		7,	256,	0,	},
    {0x1205, "NVIDIA GeForce GTX 460 v2",	7,	0,	0,	},
    {0x1206, "NVIDIA GeForce  GTX 555",		6,	192,	0,	},
    {0x1207, "NVIDIA GeForce GT 645",		6,	192,	0,	},
    {0x1208, "NVIDIA GeForce GTX 560 SE",	0,	0,	0,	},
    {0x1210, "NVIDIA GeForce GTX 570M",		0,	0,	0,	},
    {0x1211, "NVIDIA GeForce GTX 580M",		0,	0,	0,	},
    {0x1212, "NVIDIA GeForce GTX 675M",		0,	0,	0,	},
    {0x1213, "NVIDIA GeForce GTX 670M",		0,	0,	0,	},
    {0x1241, "NVIDIA GeForce GT 545",		3,	0,	0,	},
    {0x1243, "NVIDIA GeForce GT 545 ",		3,	0,	0,	},
    {0x1244, "NVIDIA GeForce GTX 550 Ti",	4,	192,	0,	},
    {0x1245, "NVIDIA GeForce GTS 450   ",	3,	192,	0,	},
    {0x1246, "NVIDIA GeForce GT 550M",		0,	0,	0,	},
    {0x1247, "NVIDIA GeForce GT 635M",		0,	0,	0,	},
    {0x1248, "NVIDIA GeForce GT 555M",		0,	0,	0,	},
    {0x1249, "NVIDIA GeForce GTS 450    ",	3,	192,	0,	},
    {0x124B, "NVIDIA GeForce GT 640  ",		3,	192,	0,	},
    {0x124D, "NVIDIA GeForce GT 555M ",		0,	0,	0,	},
    {0x1251, "NVIDIA GeForce GTX 560M",		0,	0,	0,	},
    {0x1280, "NVIDIA GeForce GT 635",		0,	0,	0,	},
    {0x1282, "NVIDIA GeForce GT 640",		0,	0,	0,	},
    {0x1284, "NVIDIA GeForce GT 630",		2,	64,	0,	},
    {0x1e07, "NVIDIA GeForce RTX 2080 Ti",  	68, 	352, 	5767168	},
    {0, "Unknown", 0, 0, 0,},
};

static struct device_properties *get_device_properties(int id)
{
	struct device_properties *p = device_list;
	while (p->id) {
		if (p->id == id)
			return p;
		p++;
	}
	return NULL;
}

