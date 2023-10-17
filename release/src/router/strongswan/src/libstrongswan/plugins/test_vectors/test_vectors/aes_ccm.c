/*
 * Copyright (C) 2010 Martin Willi
 * Copyright (C) 2010 revosec AG
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the Licenseor (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be usefulbut
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

#include <crypto/crypto_tester.h>

/**
 * Test vectors with 11 bytes nonces are hard to find, neither RFC3610 nor
 * NIST 800-38C has one. These vectors are taken from the Linux kernel,
 * originally from "fips cavs fax files on hand at Red Hat".
 */
aead_test_vector_t aes_ccm1 = {
	.alg = ENCR_AES_CCM_ICV16, .key_size = 16, .salt_size = 3,
	.len = 32, .alen = 0,
	.key	= "\x83\xac\x54\x66\xc2\xeb\xe5\x05\x2e\x01\xd1\xfc\x5d\x82\x66\x2e"
			  "\x96\xac\x59",
	.iv		= "\x30\x07\xa1\xe2\xa2\xc7\x55\x24",
	.plain	= "\x19\xc8\x81\xf6\xe9\x86\xff\x93\x0b\x78\x67\xe5\xbb\xb7\xfc\x6e"
			  "\x83\x77\xb3\xa6\x0c\x8c\x9f\x9c\x35\x2e\xad\xe0\x62\xf9\x91\xa1",
	.cipher	= "\xab\x6f\xe1\x69\x1d\x19\x99\xa8\x92\xa0\xc4\x6f\x7e\xe2\x8b\xb1"
			  "\x70\xbb\x8c\xa6\x4c\x6e\x97\x8a\x57\x2b\xbe\x5d\x98\xa6\xb1\x32"
			  "\xda\x24\xea\xd9\xa1\x39\x98\xfd\xa4\xbe\xd9\xf2\x1a\x6d\x22\xa8",
};

aead_test_vector_t aes_ccm2 = {
	.alg = ENCR_AES_CCM_ICV16, .key_size = 16, .salt_size = 3,
	.len = 32, .alen = 32,
	.key	= "\x1e\x2c\x7e\x01\x41\x9a\xef\xc0\x0d\x58\x96\x6e\x5c\xa2\x4b\xd3"
			  "\x4f\xa3\x19",
	.iv		= "\xd3\x01\x5a\xd8\x30\x60\x15\x56",
	.adata	= "\xda\xe6\x28\x9c\x45\x2d\xfd\x63\x5e\xda\x4c\xb6\xe6\xfc\xf9\xb7"
			  "\x0c\x56\xcb\xe4\xe0\x05\x7a\xe1\x0a\x63\x09\x78\xbc\x2c\x55\xde",
	.plain	= "\x87\xa3\x36\xfd\x96\xb3\x93\x78\xa9\x28\x63\xba\x12\xa3\x14\x85"
			  "\x57\x1e\x06\xc9\x7b\x21\xef\x76\x7f\x38\x7e\x8e\x29\xa4\x3e\x7e",
	.cipher	= "\x8a\x1e\x11\xf0\x02\x6b\xe2\x19\xfc\x70\xc4\x6d\x8e\xb7\x99\xab"
			  "\xc5\x4b\xa2\xac\xd3\xf3\x48\xff\x3b\xb5\xce\x53\xef\xde\xbb\x02"
			  "\xa9\x86\x15\x6c\x13\xfe\xda\x0a\x22\xb8\x29\x3d\xd8\x39\x9a\x23",
};

aead_test_vector_t aes_ccm3 = {
	.alg = ENCR_AES_CCM_ICV16, .key_size = 24, .salt_size = 3,
	.len = 0, .alen = 32,
	.key	= "\xf4\x6b\xc2\x75\x62\xfe\xb4\xe1\xa3\xf0\xff\xdd\x4e\x4b\x12\x75"
			  "\x53\x14\x73\x66\x8d\x88\xf6\x80\xa0\x20\x35",
	.iv		= "\x26\xf2\x21\x8d\x50\x20\xda\xe2",
	.adata	= "\x5b\x9e\x13\x67\x02\x5e\xef\xc1\x6c\xf9\xd7\x1e\x52\x8f\x7a\x47"
			  "\xe9\xd4\xcf\x20\x14\x6e\xf0\x2d\xd8\x9e\x2b\x56\x10\x23\x56\xe7",
	.cipher	= "\x36\xea\x7a\x70\x08\xdc\x6a\xbc\xad\x0c\x7a\x63\xf6\x61\xfd\x9b",
};

aead_test_vector_t aes_ccm4 = {
	.alg = ENCR_AES_CCM_ICV16, .key_size = 24, .salt_size = 3,
	.len = 32, .alen = 32,
	.key	= "\x56\xdf\x5c\x8f\x26\x3f\x0e\x42\xef\x7a\xd3\xce\xfc\x84\x60\x62"
			  "\xca\xb4\x40\xaf\x5f\xc9\xc9\x01\xd6\x3c\x8c",
	.iv		= "\x86\x84\xb6\xcd\xef\x09\x2e\x94",
	.adata	= "\x02\x65\x78\x3c\xe9\x21\x30\x91\xb1\xb9\xda\x76\x9a\x78\x6d\x95"
			  "\xf2\x88\x32\xa3\xf2\x50\xcb\x4c\xe3\x00\x73\x69\x84\x69\x87\x79",
	.plain	= "\x9f\xd2\x02\x4b\x52\x49\x31\x3c\x43\x69\x3a\x2d\x8e\x70\xad\x7e"
			  "\xe0\xe5\x46\x09\x80\x89\x13\xb2\x8c\x8b\xd9\x3f\x86\xfb\xb5\x6b",
	.cipher	= "\x39\xdf\x7c\x3c\x5a\x29\xb9\x62\x5d\x51\xc2\x16\xd8\xbd\x06\x9f"
			  "\x9b\x6a\x09\x70\xc1\x51\x83\xc2\x66\x88\x1d\x4f\x9a\xda\xe0\x1e"
			  "\xc7\x79\x11\x58\xe5\x6b\x20\x40\x7a\xea\x46\x42\x8b\xe4\x6f\xe1",
};

aead_test_vector_t aes_ccm5 = {
	.alg = ENCR_AES_CCM_ICV8, .key_size = 32, .salt_size = 3,
	.len = 32, .alen = 32,
	.key	= "\xe0\x8d\x99\x71\x60\xd7\x97\x1a\xbd\x01\x99\xd5\x8a\xdf\x71\x3a"
			  "\xd3\xdf\x24\x4b\x5e\x3d\x4b\x4e\x30\x7a\xb9\xd8\x53\x0a\x5e\x2b"
			  "\x1e\x29\x91",
	.iv		= "\xad\x8e\xc1\x53\x0a\xcf\x2d\xbe",
	.adata	= "\x19\xb6\x1f\x57\xc4\xf3\xf0\x8b\x78\x2b\x94\x02\x29\x0f\x42\x27"
			  "\x6b\x75\xcb\x98\x34\x08\x7e\x79\xe4\x3e\x49\x0d\x84\x8b\x22\x87",
	.plain	= "\xe1\xd9\xd8\x13\xeb\x3a\x75\x3f\x9d\xbd\x5f\x66\xbe\xdc\xbb\x66"
			  "\xbf\x17\x99\x62\x4a\x39\x27\x1f\x1d\xdc\x24\xae\x19\x2f\x98\x4c",
	.cipher	= "\x19\xb8\x61\x33\x45\x2b\x43\x96\x6f\x51\xd0\x20\x30\x7d\x9b\xc6"
			  "\x26\x3d\xf8\xc9\x65\x16\xa8\x9f\xf0\x62\x17\x34\xf2\x1e\x8d\x75"
			  "\x4e\x13\xcc\xc0\xc3\x2a\x54\x2d",
};

aead_test_vector_t aes_ccm6 = {
	.alg = ENCR_AES_CCM_ICV12, .key_size = 32, .salt_size = 3,
	.len = 32, .alen = 32,
	.key	= "\x7c\xc8\x18\x3b\x8d\x99\xe0\x7c\x45\x41\xb8\xbd\x5c\xa7\xc2\x32"
			  "\x8a\xb8\x02\x59\xa4\xfe\xa9\x2c\x09\x75\x9a\x9b\x3c\x9b\x27\x39"
			  "\xf9\xd9\x4e",
	.iv		= "\x63\xb5\x3d\x9d\x43\xf6\x1e\x50",
	.adata	= "\x57\xf5\x6b\x8b\x57\x5c\x3d\x3b\x13\x02\x01\x0c\x83\x4c\x96\x35"
			  "\x8e\xd6\x39\xcf\x7d\x14\x9b\x94\xb0\x39\x36\xe6\x8f\x57\xe0\x13",
	.plain	= "\x3b\x6c\x29\x36\xb6\xef\x07\xa6\x83\x72\x07\x4f\xcf\xfa\x66\x89"
			  "\x5f\xca\xb1\xba\xd5\x8f\x2c\x27\x30\xdb\x75\x09\x93\xd4\x65\xe4",
	.cipher	= "\xb0\x88\x5a\x33\xaa\xe5\xc7\x1d\x85\x23\xc7\xc6\x2f\xf4\x1e\x3d"
			  "\xcc\x63\x44\x25\x07\x78\x4f\x9e\x96\xb8\x88\xeb\xbc\x48\x1f\x06"
			  "\x39\xaf\x39\xac\xd8\x4a\x80\x39\x7b\x72\x8a\xf7",
};

aead_test_vector_t aes_ccm7 = {
	.alg = ENCR_AES_CCM_ICV16, .key_size = 32, .salt_size = 3,
	.len = 32, .alen = 32,
	.key	= "\xab\xd0\xe9\x33\x07\x26\xe5\x83\x8c\x76\x95\xd4\xb6\xdc\xf3\x46"
			  "\xf9\x8f\xad\xe3\x02\x13\x83\x77\x3f\xb0\xf1\xa1\xa1\x22\x0f\x2b"
			  "\x24\xa7\x8b",
	.iv		= "\x07\xcb\xcc\x0e\xe6\x33\xbf\xf5",
	.adata	= "\xd4\xdb\x30\x1d\x03\xfe\xfd\x5f\x87\xd4\x8c\xb6\xb6\xf1\x7a\x5d"
			  "\xab\x90\x65\x8d\x8e\xca\x4d\x4f\x16\x0c\x40\x90\x4b\xc7\x36\x73",
	.plain	= "\xf5\xc6\x7d\x48\xc1\xb7\xe6\x92\x97\x5a\xca\xc4\xa9\x6d\xf9\x3d"
			  "\x6c\xde\xbc\xf1\x90\xea\x6a\xb2\x35\x86\x36\xaf\x5c\xfe\x4b\x3a",
	.cipher	= "\x83\x6f\x40\x87\x72\xcf\xc1\x13\xef\xbb\x80\x21\x04\x6c\x58\x09"
			  "\x07\x1b\xfc\xdf\xc0\x3f\x5b\xc7\xe0\x79\xa8\x6e\x71\x7c\x3f\xcf"
			  "\x5c\xda\xb2\x33\xe5\x13\xe2\x0d\x74\xd1\xef\xb5\x0f\x3a\xb5\xf8",
};

aead_test_vector_t aes_ccm8 = {
	.alg = ENCR_AES_CCM_ICV8, .key_size = 16, .salt_size = 3,
	.len = 0, .alen = 0,
	.key	= "\xab\x2f\x8a\x74\xb7\x1c\xd2\xb1\xff\x80\x2e\x48\x7d\x82\xf8\xb9"
			  "\xaf\x94\x87",
	.iv		= "\x78\x35\x82\x81\x7f\x88\x94\x68",
	.cipher	= "\x41\x3c\xb8\x87\x73\xcb\xf3\xf3",
};

aead_test_vector_t aes_ccm9 = {
	.alg = ENCR_AES_CCM_ICV8, .key_size = 24, .salt_size = 3,
	.len = 0, .alen = 32,
	.key	= "\x39\xbb\xa7\xbe\x59\x97\x9e\x73\xa2\xbc\x6b\x98\xd7\x75\x7f\xe3"
			  "\xa4\x48\x93\x39\x26\x71\x4a\xc6\xee\x49\x83",
	.iv		= "\xe9\xa9\xff\xe9\x57\xba\xfd\x9e",
	.adata	= "\x44\xa6\x2c\x05\xe9\xe1\x43\xb1\x58\x7c\xf2\x5c\x6d\x39\x0a\x64"
			  "\xa4\xf0\x13\x05\xd1\x77\x99\x67\x11\xc4\xc6\xdb\x00\x56\x36\x61",
	.cipher	= "\x71\x99\xfa\xf4\x44\x12\x68\x9b",
};

aead_test_vector_t aes_ccm10 = {
	.alg = ENCR_AES_CCM_ICV8, .key_size = 32, .salt_size = 3,
	.len = 0, .alen = 0,
	.key	= "\xa4\x4b\x54\x29\x0a\xb8\x6d\x01\x5b\x80\x2a\xcf\x25\xc4\xb7\x5c"
			  "\x20\x2c\xad\x30\xc2\x2b\x41\xfb\x0e\x85\xbc\x33\xad\x0f\x2b\xff"
			  "\xee\x49\x83",
	.iv		= "\xe9\xa9\xff\xe9\x57\xba\xfd\x9e",
	.cipher	= "\x1f\xb8\x8f\xa3\xdd\x54\x00\xf2",
};

aead_test_vector_t aes_ccm11 = {
	.alg = ENCR_AES_CCM_ICV8, .key_size = 24, .salt_size = 3,
	.len = 32, .alen = 32,
	.key	= "\x58\x5d\xa0\x96\x65\x1a\x04\xd7\x96\xe5\xc5\x68\xaa\x95\x35\xe0"
			  "\x29\xa0\xba\x9e\x48\x78\xd1\xba\xee\x49\x83",
	.iv		= "\xe9\xa9\xff\xe9\x57\xba\xfd\x9e",
	.adata	= "\x44\xa6\x2c\x05\xe9\xe1\x43\xb1\x58\x7c\xf2\x5c\x6d\x39\x0a\x64"
			  "\xa4\xf0\x13\x05\xd1\x77\x99\x67\x11\xc4\xc6\xdb\x00\x56\x36\x61",
	.plain	= "\x85\x34\x66\x42\xc8\x92\x0f\x36\x58\xe0\x6b\x91\x3c\x98\x5c\xbb"
			  "\x0a\x85\xcc\x02\xad\x7a\x96\xe9\x65\x43\xa4\xc3\x0f\xdc\x55\x81",
	.cipher	= "\xfb\xe5\x5d\x34\xbe\xe5\xe8\xe7\x5a\xef\x2f\xbf\x1f\x7f\xd4\xb2"
			  "\x66\xca\x61\x1e\x96\x7a\x61\xb3\x1c\x16\x45\x52\xba\x04\x9c\x9f"
			  "\xb1\xd2\x40\xbc\x52\x7c\x6f\xb1",
};

/**
 * The vectors below are defined by ourself
 */
aead_test_vector_t aes_ccm12 = {
	.alg = ENCR_AES_CCM_ICV8, .key_size = 24, .salt_size = 3,
	.len = 32, .alen = 27,
	.key	= "\x58\x5d\xa0\x96\x65\x1a\x04\xd7\x96\xe5\xc5\x68\xaa\x95\x35\xe0"
			  "\x29\xa0\xba\x9e\x48\x78\xd1\xba\xee\x49\x83",
	.iv		= "\xe9\xa9\xff\xe9\x57\xba\xfd\x9e",
	.adata	= "\x44\xa6\x2c\x05\xe9\xe1\x43\xb1\x58\x7c\xf2\x5c\x6d\x39\x0a\x64"
			  "\xa4\xf0\x13\x05\xd1\x77\x99\x67\x11\xc4\xc6",
	.plain	= "\x85\x34\x66\x42\xc8\x92\x0f\x36\x58\xe0\x6b\x91\x3c\x98\x5c\xbb"
			  "\x0a\x85\xcc\x02\xad\x7a\x96\xe9\x65\x43\xa4\xc3\x0f\xdc\x55\x81",
	.cipher	= "\xfb\xe5\x5d\x34\xbe\xe5\xe8\xe7\x5a\xef\x2f\xbf\x1f\x7f\xd4\xb2"
			  "\x66\xca\x61\x1e\x96\x7a\x61\xb3\x1c\x16\x45\x52\xba\x04\x9c\x9f"
			  "\x24\x0e\xd1\xa5\x40\x74\xc8\x4e",
};

aead_test_vector_t aes_ccm13 = {
	.alg = ENCR_AES_CCM_ICV8, .key_size = 24, .salt_size = 3,
	.len = 27, .alen = 32,
	.key	= "\x58\x5d\xa0\x96\x65\x1a\x04\xd7\x96\xe5\xc5\x68\xaa\x95\x35\xe0"
			  "\x29\xa0\xba\x9e\x48\x78\xd1\xba\xee\x49\x83",
	.iv		= "\xe9\xa9\xff\xe9\x57\xba\xfd\x9e",
	.adata	= "\x44\xa6\x2c\x05\xe9\xe1\x43\xb1\x58\x7c\xf2\x5c\x6d\x39\x0a\x64"
			  "\xa4\xf0\x13\x05\xd1\x77\x99\x67\x11\xc4\xc6\xdb\x00\x56\x36\x61",
	.plain	= "\x85\x34\x66\x42\xc8\x92\x0f\x36\x58\xe0\x6b\x91\x3c\x98\x5c\xbb"
			  "\x0a\x85\xcc\x02\xad\x7a\x96\xe9\x65\x43\xa4",
	.cipher	= "\xfb\xe5\x5d\x34\xbe\xe5\xe8\xe7\x5a\xef\x2f\xbf\x1f\x7f\xd4\xb2"
			  "\x66\xca\x61\x1e\x96\x7a\x61\xb3\x1c\x16\x45\xa6\xe9\x3c\xa8\x50"
			  "\x4e\x62\x97",
};

aead_test_vector_t aes_ccm14 = {
	.alg = ENCR_AES_CCM_ICV8, .key_size = 24, .salt_size = 3,
	.len = 27, .alen = 27,
	.key	= "\x58\x5d\xa0\x96\x65\x1a\x04\xd7\x96\xe5\xc5\x68\xaa\x95\x35\xe0"
			  "\x29\xa0\xba\x9e\x48\x78\xd1\xba\xee\x49\x83",
	.iv		= "\xe9\xa9\xff\xe9\x57\xba\xfd\x9e",
	.adata	= "\x44\xa6\x2c\x05\xe9\xe1\x43\xb1\x58\x7c\xf2\x5c\x6d\x39\x0a\x64"
			  "\xa4\xf0\x13\x05\xd1\x77\x99\x67\x11\xc4\xc6",
	.plain	= "\x85\x34\x66\x42\xc8\x92\x0f\x36\x58\xe0\x6b\x91\x3c\x98\x5c\xbb"
			  "\x0a\x85\xcc\x02\xad\x7a\x96\xe9\x65\x43\xa4",
	.cipher	= "\xfb\xe5\x5d\x34\xbe\xe5\xe8\xe7\x5a\xef\x2f\xbf\x1f\x7f\xd4\xb2"
			  "\x66\xca\x61\x1e\x96\x7a\x61\xb3\x1c\x16\x45\x11\x03\x16\x48\xfb"
			  "\xb7\xde\xf1",
};

aead_test_vector_t aes_ccm15 = {
	.alg = ENCR_AES_CCM_ICV12, .key_size = 16, .salt_size = 3,
	.len = 32, .alen = 32,
	.key	= "\x7c\xc8\x18\x3b\x8d\x99\xe0\x7c\x45\x41\xb8\xbd\x5c\xa7\xc2\x32"
			  "\x8a\xb8\x02\x59\xa4\xfe\xa9\x2c\x09\x75\x9a\x9b\x3c\x9b\x27\x39"
			  "\xf9\xd9\x4e",
	.iv		= "\x63\xb5\x3d\x9d\x43\xf6\x1e\x50",
	.adata	= "\x57\xf5\x6b\x8b\x57\x5c\x3d\x3b\x13\x02\x01\x0c\x83\x4c\x96\x35"
			  "\x8e\xd6\x39\xcf\x7d\x14\x9b\x94\xb0\x39\x36\xe6\x8f\x57\xe0\x13",
	.plain	= "\x3b\x6c\x29\x36\xb6\xef\x07\xa6\x83\x72\x07\x4f\xcf\xfa\x66\x89"
			  "\x5f\xca\xb1\xba\xd5\x8f\x2c\x27\x30\xdb\x75\x09\x93\xd4\x65\xe4",
	.cipher	= "\x2b\x94\x71\x1a\xd3\x28\x21\xe5\xe2\xeb\x75\xe8\x09\x98\x9c\x0a"
			  "\xc9\xea\x3e\xe4\x3a\xf9\x71\x4c\x4f\x16\x73\x1d\xa5\x10\x93\x5b"
			  "\x83\xcd\xdd\x30\xb9\x3f\x86\xb3\x14\xbb\x7d\x81",
};

aead_test_vector_t aes_ccm16 = {
	.alg = ENCR_AES_CCM_ICV12, .key_size = 24, .salt_size = 3,
	.len = 32, .alen = 32,
	.key	= "\x7c\xc8\x18\x3b\x8d\x99\xe0\x7c\x45\x41\xb8\xbd\x5c\xa7\xc2\x32"
			  "\x8a\xb8\x02\x59\xa4\xfe\xa9\x2c\xf9\xd9\x4e",
	.iv		= "\x63\xb5\x3d\x9d\x43\xf6\x1e\x50",
	.adata	= "\x57\xf5\x6b\x8b\x57\x5c\x3d\x3b\x13\x02\x01\x0c\x83\x4c\x96\x35"
			  "\x8e\xd6\x39\xcf\x7d\x14\x9b\x94\xb0\x39\x36\xe6\x8f\x57\xe0\x13",
	.plain	= "\x3b\x6c\x29\x36\xb6\xef\x07\xa6\x83\x72\x07\x4f\xcf\xfa\x66\x89"
			  "\x5f\xca\xb1\xba\xd5\x8f\x2c\x27\x30\xdb\x75\x09\x93\xd4\x65\xe4",
	.cipher	= "\x48\x19\x60\xbb\x65\xa8\x00\xb8\x26\xf1\x7f\x16\x1f\x3c\xfc\x6d"
			  "\x86\x62\x10\xc5\x51\xcf\xef\x74\xac\xc6\xdf\x28\xac\x36\x6f\xa0"
			  "\x3a\x38\x24\x50\x68\x0f\x40\x1e\xaf\xea\x42\x16",
};