#pragma once
#ifndef CTGLOBJECT_H
#define CTGLOBJECT_H

#include <gl\CTGLPainter.h>
#include <common\CTObject.h>
#include <CTData>

typedef CppTools::CTData::CTFuncBase<void>::p_TFunc CTGLObjectEvent;

namespace CppTools
{
	namespace CTGL
	{
		template <typename Tx>
		class CTGLObject
			: public CTObject
		{
		public:
			virtual void draw() const = 0;
		};

		template <typename Tx>
		class CTGLObject2
			: public CTGLObject<Tx>
		{
		public:
			typedef typename CppTools::CTData::CTPoint2<Tx>	point2;
			typedef typename CppTools::CTData::CTRect2<Tx>	rect2;
			typedef typename CppTools::CTData::CTSize2<Tx>	size2;
			typedef typename CppTools::CTData::CTLine2<Tx>	line2;

			CTGLObject2(bool move = false, bool click = false) :move(move), click(click) { }

			void draw() const;

			virtual bool moved(Tx x, Tx y);
			virtual bool clicked(Tx x, Tx y);
			virtual bool released();
			virtual void reset();
			virtual void clear();

			inline void setMoveFlag(bool flag);
			inline bool getMoveFlag() const;
			inline void setClickFlag(bool flag);
			inline bool getClickFlag() const;

		protected:
			bool move, click;
		};

		template <typename Tx>
		class CTGLObject3
			: public CTGLObject<Tx>
		{
		public:
			typedef typename CppTools::CTData::CTRect3<Tx> rect3;

			void draw() const;

			virtual bool moved(Tx x, Tx y);
			virtual bool clicked(Tx x, Tx y);
			virtual bool released();
			virtual void reset();
			virtual void clear();
		};

		template <typename Tx>
		class CTGLImage2
			: public CTGLObject2<Tx>
		{
		public:
			CTGLImage2();
			CTGLImage2(const rect2& draw_rect, const rect2& texture_rect, const CTTexture2d id = 0);
			CTGLImage2(const rect2& draw_rect, const rect2& texture_rect, const std::string& filename);
			~CTGLImage2();
			void draw() const;
			
			inline void setDrawRect(rect2& rect);
			inline rect2 getDrawRect() const;
			inline void setTextureRect(rect2& rect);
			inline rect2 getTextureRect() const;
			inline void setTexture(CTTexture2d id);
			inline void setTexture(const std::string& filename);
			inline CTTexture2d getTexture() const;

		protected:
			CTTexture2d id;
			rect2 draw_rect, texture_rect;
			bool is_auto_created;
		};

		template <typename Tx>
		class CTGLButton2
			: public CTGLObject2<Tx>
		{
		public:
			CTGLButton2();
			CTGLButton2(const rect2& draw_rect, const rect2& stand_rect, const CTTexture2d stand_id = 0);
			CTGLButton2(CTGLImage2<Tx>* standi, CTGLImage2<Tx>* movei = NULL, CTGLImage2<Tx>* clicki = NULL);
			~CTGLButton2();
			void draw() const;

			//设置/返回绘图区域
			inline void setDrawRect(rect2& rect);
			inline rect2 getDrawRect() const;
			inline void resetDrawRect();

			//设置/返回静态绘图纹理和纹理坐标
			inline void setStand(CTGLImage2<Tx>* image);
			inline CTGLImage2<Tx> getStand() const;
			inline void setStand(rect2& texture_rect, CTTexture2d id);
			inline void setStandTexture(CTTexture2d stand_id);
			inline void setStandTexture(const std::string& filename);
			inline CTTexture2d getStandTexture() const;
			inline void setStandRect(rect2& stand_rect);
			inline rect2 getStandRect() const;

			//设置/返回鼠标经过时绘图纹理和纹理坐标
			inline void setMove(CTGLImage2<Tx>* image, CTGLObjectEvent event_func = NULL);
			inline CTGLImage2<Tx> getMove() const;
			inline void setMove(rect2& texture_rect, CTTexture2d id, CTGLObjectEvent event_func = NULL);
			inline void setMoveTexture(CTTexture2d move_id);
			inline void setMoveTexture(const std::string& filename);
			inline CTTexture2d getMoveTexture() const;
			inline void setMoveRect(rect2& move_rect);
			inline rect2 getMoveRect() const;
			inline void setMoveEvent(CTGLObjectEvent event_func = NULL);
			inline CTGLObjectEvent getMoveEvent() const;			

			//设置/返回点击点击时绘图纹理和纹理坐标
			inline void setClick(CTGLImage2<Tx>* image, CTGLObjectEvent event_func = NULL);
			inline CTGLImage2<Tx> getClick() const;
			inline void setClick(rect2& texture_rect, CTTexture2d id, CTGLObjectEvent event_func = NULL);
			inline void setClickTexture(CTTexture2d click_id);
			inline void setClickTexture(const std::string& filename);
			inline CTTexture2d getClickTexture() const;
			inline void setClickRect(rect2& click_rect);
			inline rect2 getClickRect() const;
			inline void setClickEvent(CTGLObjectEvent event_func = NULL);
			inline CTGLObjectEvent getClickEvent() const;

			virtual bool isMove(Tx x, Tx y);	//鼠标是否经过
			bool moved(Tx x, Tx y);				//鼠标经过触发事件
			bool clicked(Tx x, Tx y);			//鼠标按下触发事件
			bool released();					//鼠标按下并松开触发事件
			void reset();
			void clear();
			
		protected:
			rect2 draw_rect;
			CTGLImage2<Tx>* standi;
			CTGLImage2<Tx>* movei;
			CTGLImage2<Tx>* clicki;
			CTGLObjectEvent move_func, click_func;
			bool is_auto_created;
		};

		template <typename Tx>
		class CTGLObject2Manager
			: public CTGLObject2<Tx>
		{
		public:
			typedef std::list<CTGLObject2<Tx>* > p_obj2;
			CTGLObject2Manager();
			~CTGLObject2Manager();
			void draw() const;
			bool moved(Tx x, Tx y);
			bool clicked(Tx x, Tx y);
			bool released();
			void reset();
			inline void clear();
			virtual inline void push_front(CTGLObject2<Tx>* obj);
			virtual inline void pop_front();
			virtual inline void push_back(CTGLObject2<Tx>* obj);
			virtual inline void pop_back();

		protected:
			p_obj2 obj_list;
		};

		template <typename Tx>
		class CTGLMenu2
			: public CTGLObject2<Tx>
		{
		public:
			typedef CTGLButton2<Tx> button2_t;
			typedef std::list<CTGLButton2<Tx>* > p_button2;
			typedef enum _arrange_style
			{
				horizontal,
				vertical,
			} arrange_style;

			CTGLMenu2();
			~CTGLMenu2();

			inline void setDrawStyle(arrange_style style);
			inline arrange_style getDrawStyle() const;
			inline void setInterval(Tx interval);
			inline Tx getInterval() const;
			inline void setPosition(point2& position);
			inline point2 getPosition() const;
			inline void setScale(size2& size);
			inline size2 getScale() const;

			CTGLHandle addButton(CTTexture2d stand_id, CTTexture2d move_id = NULL, CTTexture2d click_id = NULL, CTGLObjectEvent move_event = NULL, CTGLObjectEvent click_event = NULL);
			void deleteButton(CTGLHandle hbutton);
			CTGLButton2<Tx>* button(CTGLHandle hbutton);

			virtual inline void push_front(CTGLButton2<Tx>* button);
			virtual inline void pop_front();
			virtual inline void push_back(CTGLButton2<Tx>* button);
			virtual inline void pop_back();
			inline void clear();

			void draw() const;
			bool moved(Tx x, Tx y);
			bool clicked(Tx x, Tx y);
			bool released();
			void reset();

		private:
			void update();
			rect2 static_rect, move_rect, click_rect;

		protected:
			int num;
			arrange_style style;
			Tx interval;
			point2 position;
			size2 size;
			rect2 draw_rect;
			p_button2 obj_list;
		};		
	}
}
#include <gl\CTGLObject.tpc>

#endif /*CTGLOBJECT_H*/