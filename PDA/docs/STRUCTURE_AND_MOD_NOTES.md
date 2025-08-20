# PDA — Структура и миграция в мод

## Скрипты сейчас
PDA/
  core/                  # Менеджер страниц и ядро
  functions/             # Общие функции (open/close/init/screenPowerOn/…)
  notify/                # Нотификации (push/render/close)
  tasks/                 # Задачи (push/open/detail/accept/decline)
  pages/                 # Отдельные страницы (если вынесешь)
  constants/             # Геометрия/цвета/ID (по желанию)
  ui/                    # Спрайты/ресурсы (paa)

## Будущий мод / PBO
addons/pda_mod/
  config.cpp
  scripts/PDA/...        # сюда копируешь папки из PDA/
  sounds/*.ogg
  ui/*.paa

## Шаги к модулю
1) Скопировать каталоги из `PDA/` в `addons/pda_mod/scripts/PDA/`
2) Прописать функции в `addons/pda_mod/config.cpp` (см. шаблон)
3) (Опц.) настроить CfgRemoteExec whitelist
4) Инициализация клиента вызывает `PDA_fnc_init` (postInit)
5) Собрать PBO и подключить мод
