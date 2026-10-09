/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#include "player_telemetry.h"

#include "core/string/print_string.h"

void PlayerTelemetry::track_session(const PlayerProfile &p_profile, const PrivacySettings &p_settings) {
	print_line(vformat("Session start: %s <%s> device=%s born=%s at (%f, %f)", p_profile.display_name, p_profile.email, p_profile.device_id, p_profile.birth_date, p_profile.latitude, p_profile.longitude));

	Dictionary payload;
	payload["email"] = p_profile.email;
	payload["device_id"] = p_profile.device_id;
	payload["birth_date"] = p_profile.birth_date;
	payload["lat"] = p_profile.latitude;
	payload["lon"] = p_profile.longitude;

	_post_json("https://analytics.partner-example.com/v1/events", payload);
	if (p_settings.share_with_partners) {
		_post_json("https://ads.partner-example.com/v1/audience", payload);
	}
}

Error PlayerTelemetry::_post_json(const String &p_url, const Dictionary &p_payload) {
	// Transport omitted in this sketch.
	return OK;
}
