#include "paths/path2.hpp"

#include <iostream>

#include "enemy/skeleton.hpp"
#include "paths/path0.hpp"
#include "player/Player.hpp"
#include "player/PlayerTools.hpp"
#include "combat.hpp"
#include "devTools.hpp"

//* Wizard Path (Increase ? Stat)
void path2 (GameState *g) {   
    std::cout << "~ Current Path: 2" << std::endl;

    if (g->dialogue2 == true) {
        cinIgnore();

        dialouge("???", "What brings thee in this parts", true);
        dialouge(g->p.name, "Who are you?", true);
        dialouge("Wizard", "I am but a humble wizard", true);
        dialouge(g->p.name, "What is a wizard doing here?", true);
        dialouge("Wizard", "You need not know of it", true);
        dialouge("Wizard", "Instead I can offer some services if you do me a favor", true);
        dialouge(g->p.name, "What favor?", true);
        dialouge("Wizard", "In the room the next of this one", true);
        dialouge("Wizard", "There are some skeletons that are ruining my garden", true);
        dialouge("Wizard", "Kill them in exchange for a something", true);

        dialouge(g->p.name, "", false);
        int move1 = accept();
        
        space();

        g->dialogue2 = false;

        
        if (move1 == 1) {
            //* Accepted Wizards Offer
            cinIgnore();

            g->qWizard.active = true;

            clear();

            dialouge("Wizard", "I knew I could count on you!", true);

            clear();
            std::cout << "~ Current Path: 2" << std::endl;
            optionsPath2(g);
        } else if (move1 == 0) {
            //* Declined Wizard Offer
            cinIgnore();

            g->qWizard.active = false;
            
            clear();
            dialouge("Wizard", "Eh? Your loss then", true);
            dialouge("Wizard", "Come to me again if you ever change your mind", true);
            
            clear();
            std::cout << "~ Current Path: 2" << std::endl;
            optionsPath2(g);
        }
    } else if (g->dialogue2 == false) { 
        optionsPath2(g);  
    }
}

void path2_2 (GameState *g) {
    clear();

    std::cout << "~ Current Path: 2-2" << std::endl;

    if (g->qWizard.active == true) {
        message(MessageType::SYS, {"Wizard Quest: Active"});
    }
    else if (g->qWizard.active == false) {
        message(MessageType::SYS, {"Wizard Quest: Inactive"});
    }

    contin();

    skeleton skeleton;

    clear();
    if (g->numOfSkeletons > 0) {
        dialouge(skeleton.name, "(Bones crackling)", true);
    }

    int move1;

    while (true) {
        //* Skeletons all dead => Wizard quest finished
        if (g->numOfSkeletons <= 0) {
            if (g->qWizard.active == true) {
                g->qWizard.finished = true;
            }
        }

        if (g->numOfSkeletons > 1) {
            message(MessageType::NARRATE, {
                "You see",
                std::to_string(g->numOfSkeletons), 
                "Skeleton Scattered In The Wizards Garden"
            });
        } else if (g->numOfSkeletons == 1) {
            message(MessageType::NARRATE, {
                "You see",
                std::to_string(g->numOfSkeletons), 
                "Skeleton In The Wizards Garden"
            });   
        } else {
            message(MessageType::NARRATE, {"The wizards garden looks clean"} );
        }

        if (g->numOfSkeletons == 3) {

            std::cout << "[1] Attack Skeleton 1" << std::endl;
            std::cout << "[2] Attack Skeleton 2" << std::endl;
            std::cout << "[3] Attack Skeleton 3" << std::endl;            
            std::cout << "[4] Turn Back" << std::endl;

        } else if (g->numOfSkeletons == 2) {

            std::cout << "[1] Attack Skeleton 1" << std::endl;
            std::cout << "[2] Attack Skeleton 2" << std::endl;
            std::cout << "[3] Turn Back" << std::endl;

        } else if (g->numOfSkeletons == 1) {

            std::cout << "[1] Attack Skeleton 1" << std::endl;
            std::cout << "[2] Turn Back" << std::endl;

        } else {
            std::cout << "[1] Turn Back" << std::endl;
        }

        message(MessageType::INPUT, {"Next move :"});
        voidPrompt();
        std::cin >> move1;

        CombatResult result;

        cinIgnore();
        //* Adaptive Choices (Changes Everytime A Skeleton Is Killed)
        if (g->numOfSkeletons == 3) {
            if (move1 == 1) {
                message(MessageType::ACTION, {"Attacking skeleton 1"});
                result = turnBasedCombat(g, &skeleton);

                if (result == CombatResult::WON) {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                } else {
                    message(MessageType::ERROR, {"Error"});
                }
            } else if (move1 == 2) {
                message(MessageType::ACTION, {"Attacking skeleton 2"});
                result = turnBasedCombat(g, &skeleton);

                if (result == CombatResult::WON) {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                } else {
                    message(MessageType::ERROR, {"Error"});
                }
            } else if (move1 == 3) {
                message(MessageType::ACTION, {"Attacking skeleton 3"});
                result = turnBasedCombat(g, &skeleton);

                if (result == CombatResult::WON) {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                }
            } else if (move1 == 4) {
                clear(); 
                message(MessageType::ACTION, {"Turning back..."});
                contin();

                clear();
                g->dialogue2 = false;
                path2(g);
                break;
            }
        } else if (g->numOfSkeletons == 2)
        {
            if (move1 == 1) {
                message(MessageType::ACTION, {"Attacking skeleton 1"});
                result = turnBasedCombat(g, &skeleton);

                if (result == CombatResult::WON) {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                } else {
                    message(MessageType::ERROR, {"Error"});
                }
            } else if (move1 == 2) {
                message(MessageType::ACTION, {"Attacking skeleton 2"});
                result = turnBasedCombat(g, &skeleton);

                if (result == CombatResult::WON) {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                } else {
                    message(MessageType::ERROR, {"Error"});
                }
            } else if (move1 == 3) { 
                clear();
                message(MessageType::ACTION, {"Turning back..."});
                contin();

                clear();
                g->dialogue2 = false;
                path2(g);
                break;
            }
        } else if (g->numOfSkeletons == 1) {
            if (move1 == 1) {
                message(MessageType::ACTION, {"Attacking skeleton 1"}); 
                result = turnBasedCombat(g, &skeleton);

                if (result == CombatResult::WON) {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                } else {
                    message(MessageType::ERROR, {"Error"});
                }
            } else if (move1 == 2) {
                clear(); 
                message(MessageType::ACTION, {"Turning back..."});
                contin();

                clear();
                g->dialogue2 = false;
                path2(g);
                break;
            }
        } else {
            if (move1 == 1) {
                clear();
                message(MessageType::ACTION, {"Turning back..."});
                contin();

                clear();
                g->dialogue2 = false;
                path2(g);
                break;
            } else {
                message(MessageType::ERROR, {"Error"});
            }
        }
    }
}

void optionsPath2 (GameState *g) {

    int move1;
    std::cout << "[1] Continue to next room " << std::endl;
    std::cout << "[2] Talk to Wizard" << std::endl;
    std::cout << "[3] Go back" << std::endl;
    
    message(MessageType::INPUT, {"Next move :"});
    voidPrompt();
    std::cin >> move1;
    
    if (move1 == 1) {
        cinIgnore();
        clear();
        message(MessageType::ACTION, {"Entering next room..."});
        contin();

        path2_2(g);
    } else if (move1 == 2) {
        if (g->qWizard.finished == true) {
            if (g->dialogue2_2 == true) {
                g->dialogue2_2 = false;
                
                cinIgnore();

                clear();
                
                dialouge("Wizard", "What do you need?", true);
                dialouge(g->p.name, "So about the reward?", true);
                dialouge("Wizard", "Done already?", true);
                dialouge(g->p.name, "Yup", true);
                dialouge("Wizard", "In return I can make you stronger!", true);
                dialouge(g->p.name, "Stronger? how?", true);
                dialouge("Wizard", "All I need is gold and I can magically enhance you", true);
                dialouge("Wizard", "Try giving me some of that gold you got from killing those skeletons", false);

                clear();
                statUp(g);

                optionsPath2(g);
            } else {
                int move2;

                clear();
                dialouge("Wizard", "Mmmhh...", true);
                cinIgnore();

                while (true) {
                    std::cout << "[1] Level Up Stats" << std::endl;
                    std::cout << "[2] Talk" << std::endl;
                    std::cout << "[3] Nevermind" << std::endl;
                    
                    message(MessageType::INPUT, {"Next move :"});
                    voidPrompt();
                    std::cin >> move2;
    
                    if (move2 == 1) {
                        statUp(g);
                        break;
                    } else if (move2 == 2) {
                        dialouge("Wizard", "My senses are telling me that a fortune awaits for you in the farthest path", true);
                        
                        continue;
                    } else if (move2 == 3) {
                        path2(g);
                        break;
                    } else if (std::cin.fail()) {
                        validNum();
                    } else {
                        message(MessageType::ERROR, {"Invalid number"});
                    }
                }
            }       
        } else {
            int move2;

            cinIgnore();

            clear();
            message(MessageType::ACTION, {"Approaching the wizard"});
            contin();

            clear();
            if (g->qWizard.active == true) {
                dialouge("Wizard", "Stop wasting time, you have skeletons to kill!", true);

                clear();
                path2(g);
            } else if (g->qWizard.active == false) {
                dialouge("Wizard", "Ready To Take My Offer?", false);
                yn();
                std::cin >> move2;

                if (move2 == 1) {
                    g->qWizard.active = true;
                    g->dialogue2_2 = false; //* Prevent double dialogue when talking to the wizard again

                    cinIgnore();

                    clear();
                    dialouge("Wizard", "Nice! Now Go Slay Me Some Skeletons", true);

                    if (g->numOfSkeletons <= 0) {
                        g->qWizard.finished = true; 
                        dialouge("Wizard", "What?", true);
                        dialouge("Wizard", "You already killed them?", true);
                        dialouge("Wizard", "Alright then", true);
                        dialouge("Wizard", "I Can Enhance Your Stats In Exchange For Gold", true);
                        dialouge("Wizard", "Here try using the gold you have", true);

                        clear();
                        statUp(g);

                        path2(g);
                    } else {                        
                        clear();
                        path2(g);
                    }
                } else if (move2 == 2) {
                    clear();
                    cinIgnore();
                    dialouge("Wizard", "Stop wasting my time then!", true);
                    
                    clear();
                    path2(g);
                } else if (std::cin.fail()) {
                    validNum();
                } else {
                    message(MessageType::ERROR, {"Invalid number"});
                }
            }
        }
    }                                                           
    else if (move1 == 3) {
        clear();
        message(MessageType::NARRATE, {"Here again..."});
        path0(g);
    } else if (std::cin.fail()) {
        validNum();    
    } else {
        message(MessageType::ERROR, {"Invalid number"});
    }   
}