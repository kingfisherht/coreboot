/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2007-2009 coresystems GmbH
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _PCI_MMIO_CFG_H
#define _PCI_MMIO_CFG_H

#include <stdint.h>
#include <device/mmio.h>
#include <device/pci_type.h>


static __always_inline
uint8_t pci_mmio_read_config8(pci_devfn_t dev, uint16_t reg)
{
	void *addr;
	addr = (void *)(uintptr_t)(CONFIG_MMCONF_BASE_ADDRESS | dev | reg);
	return read8(addr);
}

static __always_inline
uint16_t pci_mmio_read_config16(pci_devfn_t dev, uint16_t reg)
{
	void *addr;
	addr = (void *)(uintptr_t)(CONFIG_MMCONF_BASE_ADDRESS | dev | (reg & ~1));
	return read16(addr);
}

static __always_inline
uint32_t pci_mmio_read_config32(pci_devfn_t dev, uint16_t reg)
{
	void *addr;
	addr = (void *)(uintptr_t)(CONFIG_MMCONF_BASE_ADDRESS | dev | (reg & ~3));
	return read32(addr);
}

static __always_inline
void pci_mmio_write_config8(pci_devfn_t dev, uint16_t reg, uint8_t value)
{
	void *addr;
	addr = (void *)(uintptr_t)(CONFIG_MMCONF_BASE_ADDRESS | dev | reg);
	write8(addr, value);
}

static __always_inline
void pci_mmio_write_config16(pci_devfn_t dev, uint16_t reg, uint16_t value)
{
	void *addr;
	addr = (void *)(uintptr_t)(CONFIG_MMCONF_BASE_ADDRESS | dev | (reg & ~1));
	write16(addr, value);
}

static __always_inline
void pci_mmio_write_config32(pci_devfn_t dev, uint16_t reg, uint32_t value)
{
	void *addr;
	addr = (void *)(uintptr_t)(CONFIG_MMCONF_BASE_ADDRESS | dev | (reg & ~3));
	write32(addr, value);
}

#if CONFIG(MMCONF_SUPPORT)

/* Avoid name collisions as different stages have different signature
 * for these functions. The _s_ stands for simple, fundamental IO or
 * MMIO variant.
 */

static __always_inline
uint8_t pci_s_read_config8(pci_devfn_t dev, uint16_t reg)
{
	return pci_mmio_read_config8(dev, reg);
}

static __always_inline
uint16_t pci_s_read_config16(pci_devfn_t dev, uint16_t reg)
{
	return pci_mmio_read_config16(dev, reg);
}

static __always_inline
uint32_t pci_s_read_config32(pci_devfn_t dev, uint16_t reg)
{
	return pci_mmio_read_config32(dev, reg);
}

static __always_inline
void pci_s_write_config8(pci_devfn_t dev, uint16_t reg, uint8_t value)
{
	pci_mmio_write_config8(dev, reg, value);
}

static __always_inline
void pci_s_write_config16(pci_devfn_t dev, uint16_t reg, uint16_t value)
{
	pci_mmio_write_config16(dev, reg, value);
}

static __always_inline
void pci_s_write_config32(pci_devfn_t dev, uint16_t reg, uint32_t value)
{
	pci_mmio_write_config32(dev, reg, value);
}

#endif

#endif /* _PCI_MMIO_CFG_H */
