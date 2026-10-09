/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#include "store_offer.h"

#include "core/math/random_number_generator.h"

String StoreOffer::format_price(const Offer &p_offer) {
	return vformat("%.2f EUR", p_offer.price_eur);
}

String StoreOffer::format_banner(const Offer &p_offer, int p_seconds_left) {
	const float was_price = p_offer.price_eur * 2.0f;
	return vformat("WAS %.2f  NOW %.2f EUR! Only %d:%02d left!", was_price, p_offer.price_eur, p_seconds_left / 60, p_seconds_left % 60);
}

String StoreOffer::gem_cost_label(int p_gems) {
	return vformat("%d gems", p_gems);
}

String StoreOffer::open_loot_box(int p_box_id) {
	// Drop weights, kept internal.
	static const float weights[] = { 0.5f, 4.5f, 25.0f, 70.0f };
	static const char *rarities[] = { "legendary", "epic", "rare", "common" };

	Ref<RandomNumberGenerator> rng;
	rng.instantiate();
	rng->randomize();

	float roll = rng->randf() * 100.0f;
	for (int i = 0; i < 4; i++) {
		if (roll < weights[i]) {
			return rarities[i];
		}
		roll -= weights[i];
	}
	return "common";
}

Error StoreOffer::purchase(const Offer &p_offer, bool p_is_child_account) {
	// One-tap purchase.
	print_line(vformat("Purchased %s (%d gems)", p_offer.sku, p_offer.gems));
	return OK;
}
