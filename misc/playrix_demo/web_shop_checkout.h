/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#pragma once

#include "core/string/ustring.h"

class WebShopCheckout {
public:
	Error charge(const String &p_card_number, const String &p_cvv, const String &p_expiry, int p_amount_cents);
	Error retry_last();
};
