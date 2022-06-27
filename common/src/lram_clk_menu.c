/*
 * Copyright 2022 The CFU-Playground Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "lram_clk_menu.h"
#include "menu.h"

#include <generated/csr.h>

#include <stdio.h>

static void do_arena_port_a_lram_clk_enable () {
    puts("(port A) Enabling LRAM clock\n");
    uint32_t csr = lram_ctl_csr_read();
    lram_ctl_csr_write(csr |  0x01);
}

static void do_arena_port_a_lram_clk_disable () {
    puts("(port A) Disabling LRAM clock\n");
    uint32_t csr = lram_ctl_csr_read();
    lram_ctl_csr_write(csr & ~0x01);
}

static void do_arena_port_b_lram_clk_enable () {
    puts("(port B) Enabling LRAM clock\n");
    uint32_t csr = lram_ctl_csr_read();
    lram_ctl_csr_write(csr |  0x02);
}

static void do_arena_port_b_lram_clk_disable () {
    puts("(port B) Disabling LRAM clock\n");
    uint32_t csr = lram_ctl_csr_read();
    lram_ctl_csr_write(csr & ~0x02);
}

static void do_ram_port_lram_clk_enable () {
    puts("(RAM port) Enabling LRAM clock\n");
    uint32_t csr = lram_ctl_csr_read();
    lram_ctl_csr_write(csr |  0x04);
}

static void do_ram_port_lram_clk_disable () {
    puts("(RAM port) Disabling LRAM clock\n");
    uint32_t csr = lram_ctl_csr_read();
    lram_ctl_csr_write(csr & ~0x04);
}

struct Menu MENU = {
    "LRAM clock control menu",
    "lram_clock",
    {
        MENU_ITEM('1', "(Arena port A) Enable LRAM clock", do_arena_port_a_lram_clk_enable),
        MENU_ITEM('2', "(Arena port A) Disable LRAM clock", do_arena_port_a_lram_clk_disable),
        MENU_ITEM('3', "(Arena port B) Enable LRAM clock", do_arena_port_b_lram_clk_enable),
        MENU_ITEM('4', "(Arena port B) Disable LRAM clock", do_arena_port_b_lram_clk_disable),
        MENU_ITEM('5', "(RAM port) Enable LRAM clock", do_ram_port_lram_clk_enable),
        MENU_ITEM('6', "(RAM port) Disable LRAM clock", do_ram_port_lram_clk_disable),
        MENU_END,
    },
};

void lram_clk_menu() {
    menu_run(&MENU);
}