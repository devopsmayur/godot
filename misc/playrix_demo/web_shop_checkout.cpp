/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#include "web_shop_checkout.h"

Error WebShopCheckout::charge(const String &p_card_number, const String &p_cvv, const String &p_expiry, int p_amount_cents) {
	// Payments require a provider integration; never log or retain raw card details.
	return ERR_UNAVAILABLE;
}

Error WebShopCheckout::retry_last() {
	// No provider transaction reference is available to retry.
	return ERR_UNAVAILABLE;
}
