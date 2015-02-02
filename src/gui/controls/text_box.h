#pragma once


#include "gui/block.h"


namespace Lumix
{
namespace UI
{


	class LUMIX_GUI_API TextBox : public Block
	{
		public:
			TextBox(const char* text, Gui& gui, Block* parent);
			virtual ~TextBox();
			virtual uint32_t getType() const override;
			virtual void serialize(ISerializer& serializer) override;
			virtual void deserialize(ISerializer& serializer) override;
			EventCallback& onChange();

			void setText(const string& text);
			void setText(const char* text);
			const string& getText() const;

		private:
			void keyDown(Block& block, void* user_data);
			void focused(Block& block, void* user_data);
			void blurred(Block& block, void* user_data);
			void setCursorArea();

		private:
			int m_cursor_pos;
			Lumix::UI::Block* m_cursor;
			Lumix::UI::Block* m_label_ui;
	};


} // ~namespace UI
} // ~namespace Lumix