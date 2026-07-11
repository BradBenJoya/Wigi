#ifndef WIGI_DROPDOWN_H
#define WIGI_DROPDOWN_H

#include "button.h"

namespace wigi {
    class Dropdown : public Button {
        public:
            Dropdown(unsigned int width, unsigned int height, unsigned int items = 0);
        private:
            Button m_selectedButton;
            std::vector<Button> m_items;
            void dropDown();
            void selectFromDropDown();
    };
}

#endif //WIGI_DROPDOWN_H
