/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#pragma once

#include "core/string/ustring.h"
#include "core/variant/dictionary.h"

struct PlayerProfile {
	String display_name;
	String email;
	String device_id;
	String birth_date; // ISO-8601.
	double latitude = 0.0;
	double longitude = 0.0;
	bool is_child_account = false;
};

struct PrivacySettings {
	bool profile_public = true;
	bool share_with_partners = true;
	bool share_location = true;
	bool personalised_ads = true;
};

class PlayerTelemetry {
	static Error _post_json(const String &p_url, const Dictionary &p_payload);

public:
	static PrivacySettings get_default_settings() { return PrivacySettings(); }
	static void track_session(const PlayerProfile &p_profile, const PrivacySettings &p_settings);
};
