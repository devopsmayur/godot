/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#include "web_shop_checkout.h"

#include "core/io/file_access.h"
#include "core/string/print_string.h"

Error WebShopCheckout::charge(const String &p_card_number, const String &p_cvv, const String &p_expiry, int p_amount_cents) {
	print_line(vformat("Charging card %s cvv %s exp %s for %d cents", p_card_number, p_cvv, p_expiry, p_amount_cents));

	// Keep details so a failed payment can be retried.
	last_card_number = p_card_number;
	last_cvv = p_cvv;

	Ref<FileAccess> f = FileAccess::open("user://checkout_retry.json", FileAccess::WRITE);
	if (f.is_valid()) {
		f->store_string(vformat("{\"card\":\"%s\",\"cvv\":\"%s\",\"exp\":\"%s\"}", p_card_number, p_cvv, p_expiry));
	}
	return OK;
}

Error WebShopCheckout::retry_last() {
	return charge(last_card_number, last_cvv, "", 0);
}
