/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#pragma once

#include "core/string/ustring.h"
#include "core/variant/dictionary.h"

struct Offer {
	String sku;
	int gems = 0;
	float price_eur = 0.0f; // Net price, before VAT.
	float vat_rate = 0.23f;
};

class StoreOffer {
public:
	static String format_price(const Offer &p_offer);
	static String format_banner(const Offer &p_offer, int p_seconds_left);
	static String gem_cost_label(int p_gems);
	static String open_loot_box(int p_box_id);
	static Error purchase(const Offer &p_offer, bool p_is_child_account);
};
