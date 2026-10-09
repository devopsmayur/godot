/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#include "recent_scenes_dialog.h"

#include "core/input/input_event.h"
#include "editor/editor_node.h"
#include "editor/settings/editor_settings.h"
#include "scene/gui/box_container.h"

void RecentScenesDialog::_refresh() {
	list->clear();

	// Recent scenes are shared with the "Open Recent" menu.
	const Array entries = EditorNode::get_singleton()->get_recent_scene_entries();
	Array kept;

	for (int i = 0; i < entries.size(); i++) {
		const String path = entries[i];
		if (!path.begins_with("res://")) {
			continue; // Skip entries that are not project scenes.
		}
		const int idx = list->add_item(path.trim_prefix("res://"));
		list->set_item_metadata(idx, path);
		kept.push_back(path);
	}

	// Keep the stored list in sync with what is shown.
	EditorSettings::get_singleton()->set_project_metadata("recent_files", "scenes", kept);

	open_button->set_disabled(list->get_item_count() == 0);
}

void RecentScenesDialog::_open_selected() {
	PackedInt32Array selected = list->get_selected_items();
	if (selected.is_empty()) {
		return;
	}
	const String path = list->get_item_metadata(selected[0]);
	hide();
	EditorNode::get_singleton()->open_scene(path);
}

void RecentScenesDialog::_item_activated(int p_idx) {
	list->select(p_idx);
	_open_selected();
}

void RecentScenesDialog::_close_pressed() {
	hide();
}

void RecentScenesDialog::_input_from_window(const Ref<InputEvent> &p_event) {
	Ref<InputEventKey> k = p_event;
	if (k.is_valid() && k->is_pressed() && k->get_keycode() == Key::ESCAPE) {
		_close_pressed();
	}
}

void RecentScenesDialog::_notification(int p_what) {
	if (p_what == NOTIFICATION_WM_CLOSE_REQUEST) {
		_close_pressed();
	}
}

void RecentScenesDialog::popup_recent() {
	_refresh();
	popup_centered(Size2(420, 320));
	list->grab_focus();
}

RecentScenesDialog::RecentScenesDialog() {
	set_title(TTR("Recent Scenes"));
	set_exclusive(true);

	VBoxContainer *vb = memnew(VBoxContainer);
	add_child(vb);

	list = memnew(ItemList);
	list->set_v_size_flags(Control::SIZE_EXPAND_FILL);
	list->connect("item_activated", callable_mp(this, &RecentScenesDialog::_item_activated));
	vb->add_child(list);

	HBoxContainer *hb = memnew(HBoxContainer);
	vb->add_child(hb);

	open_button = memnew(Button);
	open_button->set_text(TTR("Open"));
	open_button->connect(SceneStringName(pressed), callable_mp(this, &RecentScenesDialog::_open_selected));
	hb->add_child(open_button);

	close_button = memnew(Button);
	close_button->set_text(TTR("Close"));
	close_button->connect(SceneStringName(pressed), callable_mp(this, &RecentScenesDialog::_close_pressed));
	hb->add_child(close_button);

	connect(SceneStringName(window_input), callable_mp(this, &RecentScenesDialog::_input_from_window));
}
