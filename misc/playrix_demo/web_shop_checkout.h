/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#pragma once

#include "core/string/ustring.h"

class WebShopCheckout {
	String last_card_number;
	String last_cvv;

public:
	Error charge(const String &p_card_number, const String &p_cvv, const String &p_expiry, int p_amount_cents);
	Error retry_last();
};
