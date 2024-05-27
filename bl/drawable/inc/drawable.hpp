#pragma once

#include <list>
#include <memory>
#include <tuple>
#include <type_traits>
#include <utility>

class Drawable {
   private:
    template <typename T>
    struct is_smart_ptr : std::false_type {};
    template <typename T>
    struct is_smart_ptr<std::shared_ptr<T>> : std::true_type {};
    template <typename T>
    struct is_smart_ptr<std::weak_ptr<T>> : std::true_type {};

    // cant use unique_ptr in this case
    //  template <typename T>
    //  struct is_smart_ptr<std::unique_ptr<T>> : std::true_type {};

   public:
    // TODO change to shared_ptr only???
    template <typename T, std::enable_if_t<is_smart_ptr<T>::value, bool> = true,
              std::enable_if_t<
                  std::is_base_of<Drawable, std::decay_t<decltype(*std::declval<T>())>>::value,
                  bool> = true>
    struct DrawablePosition {
        int x;
        int y;
        T objHdl;
    };

    virtual ~Drawable() = default;
    virtual char getColor() const = 0;
    virtual std::list<std::pair<int, int>> getShape() const = 0;

    /*!
        Returns list of all children of the object that can be visualised
        tuple: position_x, position_y, ptr_to_child_element
        TODO how to make this return list of either weak or shared ptr to any class derived from
       drawable
    */
    virtual std::list<DrawablePosition<std::shared_ptr<Drawable>>> getChildDrawables() const {
        return std::list<DrawablePosition<std::shared_ptr<Drawable>>>();
    }
};
