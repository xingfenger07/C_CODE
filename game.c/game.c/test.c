#define _CRT_SECURE_NO_WARNINGS 1



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PLAYERS 8
#define MAX_HAND_CARDS 10
#define MAX_DECK_CARDS 108

// 卡牌类型枚举
typedef enum {
    BASIC,      // 基本牌
    TRICK,      // 锦囊牌
    EQUIPMENT   // 装备牌
} CardType;

// 基本牌类型
typedef enum {
    ATTACK,     // 杀
    DEFENSE,    // 闪
    HEAL        // 桃
} BasicCardType;

// 角色结构体
typedef struct {
    char name[20];
    int health;
    int max_health;
    int hand_cards[MAX_HAND_CARDS];
    int hand_count;
    int role; // 0: 主公, 1: 忠臣, 2: 反贼, 3: 内奸
    int alive;
} Player;

// 卡牌结构体
typedef struct {
    int id;
    CardType type;
    int subtype;
    char name[20];
    char description[100];
} Card;

// 游戏状态结构体
typedef struct {
    Player players[MAX_PLAYERS];
    int player_count;
    Card deck[MAX_DECK_CARDS];
    int deck_count;
    int discard_pile[MAX_DECK_CARDS];
    int discard_count;
    int current_player;
    int game_over;
} GameState;

// 初始化卡牌
void initialize_deck(GameState* game) {
    int i, card_id = 0;

    // 初始化基本牌
    for (i = 0; i < 30; i++) {
        game->deck[card_id].id = card_id;
        game->deck[card_id].type = BASIC;
        game->deck[card_id].subtype = ATTACK;
        strcpy(game->deck[card_id].name, "杀");
        strcpy(game->deck[card_id].description, "对一名其他角色使用，目标角色需打出一张【闪】，否则受到1点伤害");
        card_id++;
    }

    for (i = 0; i < 15; i++) {
        game->deck[card_id].id = card_id;
        game->deck[card_id].type = BASIC;
        game->deck[card_id].subtype = DEFENSE;
        strcpy(game->deck[card_id].name, "闪");
        strcpy(game->deck[card_id].description, "用于响应【杀】");
        card_id++;
    }

    for (i = 0; i < 8; i++) {
        game->deck[card_id].id = card_id;
        game->deck[card_id].type = BASIC;
        game->deck[card_id].subtype = HEAL;
        strcpy(game->deck[card_id].name, "桃");
        strcpy(game->deck[card_id].description, "目标角色回复1点体力");
        card_id++;
    }

    // 初始化锦囊牌
    for (i = 0; i < 4; i++) {
        game->deck[card_id].id = card_id;
        game->deck[card_id].type = TRICK;
        game->deck[card_id].subtype = 0; // 顺手牵羊
        strcpy(game->deck[card_id].name, "顺手牵羊");
        strcpy(game->deck[card_id].description, "获得距离为1的一名其他角色区域内的一张牌");
        card_id++;
    }

    for (i = 0; i < 3; i++) {
        game->deck[card_id].id = card_id;
        game->deck[card_id].type = TRICK;
        game->deck[card_id].subtype = 1; // 过河拆桥
        strcpy(game->deck[card_id].name, "过河拆桥");
        strcpy(game->deck[card_id].description, "弃置一名其他角色区域内的一张牌");
        card_id++;
    }

    game->deck_count = card_id;
}

// 洗牌
void shuffle_deck(GameState* game) {
    int i, j;
    Card temp;

    for (i = 0; i < game->deck_count; i++) {
        j = rand() % game->deck_count;
        temp = game->deck[i];
        game->deck[i] = game->deck[j];
        game->deck[j] = temp;
    }
}

// 初始化玩家
void initialize_players(GameState* game, int count) {
    int i;
    game->player_count = count;

    for (i = 0; i < count; i++) {
        sprintf(game->players[i].name, "玩家%d", i + 1);
        game->players[i].health = 4;
        game->players[i].max_health = 4;
        game->players[i].hand_count = 0;
        game->players[i].alive = 1;

        // 分配角色
        if (i == 0) {
            game->players[i].role = 0; // 主公
        }
        else if (i < count / 2) {
            game->players[i].role = 1; // 忠臣
        }
        else if (i < count - 1) {
            game->players[i].role = 2; // 反贼
        }
        else {
            game->players[i].role = 3; // 内奸
        }
    }
}

// 发牌
void deal_cards(GameState* game, int cards_per_player) {
    int i, j;

    for (i = 0; i < game->player_count; i++) {
        for (j = 0; j < cards_per_player && game->deck_count > 0; j++) {
            game->players[i].hand_cards[game->players[i].hand_count] = game->deck[game->deck_count - 1].id;
            game->players[i].hand_count++;
            game->deck_count--;
        }
    }
}

// 初始化游戏
void initialize_game(GameState* game, int player_count) {
    srand(time(NULL));

    initialize_deck(game);
    shuffle_deck(game);
    initialize_players(game, player_count);
    deal_cards(game, 4);

    game->current_player = 0;
    game->game_over = 0;
    game->discard_count = 0;
}

// 显示玩家状态
void display_player_status(GameState* game, int player_index) {
    Player* p = &game->players[player_index];
    printf("=== %s ===\n", p->name);
    printf("角色: ");
    switch (p->role) {
    case 0: printf("主公"); break;
    case 1: printf("忠臣"); break;
    case 2: printf("反贼"); break;
    case 3: printf("内奸"); break;
    }
    printf("\n");
    printf("体力: %d/%d\n", p->health, p->max_health);
    printf("手牌数: %d\n", p->hand_count);
    printf("手牌: ");
    int i;
    for (i = 0; i < p->hand_count; i++) {
        int card_id = p->hand_cards[i];
        printf("[%d:%s] ", i, game->deck[card_id].name);
    }
    printf("\n\n");
}

// 抽牌
void draw_card(GameState* game, int player_index) {
    if (game->deck_count > 0) {
        Player* p = &game->players[player_index];
        if (p->hand_count < MAX_HAND_CARDS) {
            p->hand_cards[p->hand_count] = game->deck[game->deck_count - 1].id;
            p->hand_count++;
            game->deck_count--;
            printf("%s 抽了一张牌\n", p->name);
        }
        else {
            printf("%s 手牌已满，无法抽牌\n", p->name);
        }
    }
    else {
        printf("牌堆已空，无法抽牌\n");
    }
}

// 使用卡牌
void use_card(GameState* game, int player_index, int card_index, int target_index) {
    Player* user = &game->players[player_index];
    Player* target = &game->players[target_index];

    if (card_index < 0 || card_index >= user->hand_count) {
        printf("无效的卡牌选择\n");
        return;
    }

    int card_id = user->hand_cards[card_index];
    Card* card = &game->deck[card_id];

    printf("%s 对 %s 使用了 %s\n", user->name, target->name, card->name);

    // 处理卡牌效果
    if (card->type == BASIC) {
        if (card->subtype == ATTACK) {
            // 检查目标是否有闪
            int has_defense = 0;
            int i;
            for (i = 0; i < target->hand_count; i++) {
                int target_card_id = target->hand_cards[i];
                if (game->deck[target_card_id].type == BASIC &&
                    game->deck[target_card_id].subtype == DEFENSE) {
                    has_defense = 1;
                    printf("%s 使用了闪响应\n", target->name);

                    // 移除闪
                    for (; i < target->hand_count - 1; i++) {
                        target->hand_cards[i] = target->hand_cards[i + 1];
                    }
                    target->hand_count--;
                    break;
                }
            }

            if (!has_defense) {
                printf("%s 受到1点伤害\n", target->name);
                target->health--;
                if (target->health <= 0) {
                    printf("%s 阵亡了！\n", target->name);
                    target->alive = 0;
                    // 检查游戏是否结束
                    int loyal_count = 0, rebel_count = 0;
                    for (i = 0; i < game->player_count; i++) {
                        if (game->players[i].alive) {
                            if (game->players[i].role == 0 || game->players[i].role == 1) {
                                loyal_count++;
                            }
                            else if (game->players[i].role == 2) {
                                rebel_count++;
                            }
                        }
                    }

                    if (rebel_count == 0) {
                        printf("主公和忠臣获胜！\n");
                        game->game_over = 1;
                    }
                    else if (loyal_count == 0) {
                        printf("反贼获胜！\n");
                        game->game_over = 1;
                    }
                }
            }
        }
        else if (card->subtype == HEAL) {
            if (target->health < target->max_health) {
                target->health++;
                printf("%s 回复了1点体力\n", target->name);
            }
            else {
                printf("%s 体力已满，无法使用桃\n", target->name);
            }
        }
    }

    // 将使用的卡牌放入弃牌堆
    game->discard_pile[game->discard_count] = card_id;
    game->discard_count++;

    // 从玩家手牌中移除卡牌
    for (; card_index < user->hand_count - 1; card_index++) {
        user->hand_cards[card_index] = user->hand_cards[card_index + 1];
    }
    user->hand_count--;
}

// 玩家回合
void player_turn(GameState* game) {
    Player* current = &game->players[game->current_player];

    if (!current->alive) {
        printf("%s 已阵亡，跳过回合\n", current->name);
        game->current_player = (game->current_player + 1) % game->player_count;
        return;
    }

    printf("\n====== %s 的回合 ======\n", current->name);
    display_player_status(game, game->current_player);

    // 抽牌阶段
    printf("抽牌阶段:\n");
    draw_card(game, game->current_player);
    draw_card(game, game->current_player);

    // 出牌阶段
    printf("\n出牌阶段:\n");
    int action_taken = 0;

    while (!action_taken) {
        printf("选择行动:\n");
        printf("1. 使用卡牌\n");
        printf("2. 结束回合\n");
        printf("选择: ");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            if (current->hand_count == 0) {
                printf("没有手牌可以使用\n");
                continue;
            }

            printf("选择要使用的卡牌 (0-%d): ", current->hand_count - 1);
            int card_index;
            scanf("%d", &card_index);

            printf("选择目标玩家 (0-%d): ", game->player_count - 1);
            int target_index;
            scanf("%d", &target_index);

            if (target_index == game->current_player) {
                printf("不能对自己使用卡牌\n");
                continue;
            }

            if (!game->players[target_index].alive) {
                printf("目标玩家已阵亡\n");
                continue;
            }

            use_card(game, game->current_player, card_index, target_index);
            action_taken = 1;
        }
        else if (choice == 2) {
            printf("结束回合\n");
            action_taken = 1;
        }
        else {
            printf("无效选择\n");
        }
    }

    // 弃牌阶段
    printf("\n弃牌阶段:\n");
    while (current->hand_count > current->health) {
        printf("手牌数超过体力值，需要弃牌\n");
        printf("当前手牌: ");
        int i;
        for (i = 0; i < current->hand_count; i++) {
            int card_id = current->hand_cards[i];
            printf("[%d:%s] ", i, game->deck[card_id].name);
        }
        printf("\n选择要弃置的卡牌 (0-%d): ", current->hand_count - 1);

        int discard_index;
        scanf("%d", &discard_index);

        if (discard_index >= 0 && discard_index < current->hand_count) {
            int card_id = current->hand_cards[discard_index];
            printf("弃置了 %s\n", game->deck[card_id].name);

            // 将卡牌放入弃牌堆
            game->discard_pile[game->discard_count] = card_id;
            game->discard_count++;

            // 从玩家手牌中移除卡牌
            for (; discard_index < current->hand_count - 1; discard_index++) {
                current->hand_cards[discard_index] = current->hand_cards[discard_index + 1];
            }
            current->hand_count--;
        }
        else {
            printf("无效选择\n");
        }
    }

    // 切换到下一玩家
    game->current_player = (game->current_player + 1) % game->player_count;
}

// 主游戏循环
void game_loop(GameState* game) {
    printf("====== 三国杀简化版 ======\n");
    printf("游戏开始！\n\n");

    while (!game->game_over) {
        player_turn(game);
    }

    printf("游戏结束！\n");
}

int main() {
    GameState game;
    int player_count;

    printf("请输入玩家数量 (4-8): ");
    scanf("%d", &player_count);

    if (player_count < 4 || player_count > MAX_PLAYERS) {
        printf("玩家数量必须在4到8之间\n");
        return 1;
    }

    initialize_game(&game, player_count);
    game_loop(&game);

    return 0;
}