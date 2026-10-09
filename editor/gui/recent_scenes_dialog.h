/**************************************************************************/
/*  Demo file for CodeRabbit evaluation                                   */
/**************************************************************************/

#pragma once

#include "scene/gui/button.h"
#include "scene/gui/item_list.h"
#include "scene/main/window.h"

// Quick-switch dialog listing recently opened scenes.
class RecentScenesDialog : public Window {
	GDCLASS(RecentScenesDialog, Window);

	ItemList *list = nullptr;
	Button *open_button = nullptr;
	Button *close_button = nullptr;

	void _refresh();
	void _open_selected();
	void _item_activated(int p_idx);
	void _close_pressed();
	void _input_from_window(const Ref<InputEvent> &p_event);

protected:
	void _notification(int p_what);
	static void _bind_methods() {}

public:
	void popup_recent();

	RecentScenesDialog();
};
