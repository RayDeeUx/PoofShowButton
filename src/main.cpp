#include <Geode/Geode.hpp>
#include <Geode/modify/CommentCell.hpp>
#include <regex>

using namespace geode::prelude;

class $modify(CommentCell) {
	static void onModify(auto & self)
    {
        self.setHookPriority("CommentCell::loadFromComment", 1000);
    }
	void loadFromComment(GJComment* p0) {
		CommentCell::loadFromComment(p0);
		try
		{
			if (Mod::get()->getSettingValue<bool>("enabled") && p0->m_isSpam) this->getChildByIDRecursive("spam-button")->setScale(0);
		}
		catch(const std::exception& e) {}
	}
};