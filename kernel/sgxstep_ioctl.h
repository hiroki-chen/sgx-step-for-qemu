/*
 *  This file is part of the SGX-Step enclave execution control framework.
 *
 *  Copyright (C) 2017 Jo Van Bulck <jo.vanbulck@cs.kuleuven.be>,
 *                     Raoul Strackx <raoul.strackx@cs.kuleuven.be>
 *
 *  SGX-Step is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SGX-Step is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SGX-Step. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SGX_STEP_IOCTL_H_INC
#define SGX_STEP_IOCTL_H_INC

#include <linux/ioctl.h>

#define SGX_STEP_IOCTL_MAGIC            'L'
#define SGX_STEP_IOCTL_GET_PT_MAPPING   _IOWR(SGX_STEP_IOCTL_MAGIC, 0, address_mapping_t)
#define SGX_STEP_IOCTL_INVPG            _IOWR(SGX_STEP_IOCTL_MAGIC, 1, invpg_t)

typedef struct {
	uint64_t virt;
	uint64_t phys;
	uint64_t pgd_phys_address;
	uint64_t pgd;
	uint64_t pud;
	uint64_t pmd;
	uint64_t pte;
} address_mapping_t;

typedef struct {
    uint64_t adrs;
} invpg_t;

#endif
