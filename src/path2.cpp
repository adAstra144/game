#include "path2.h"

// - - - - - - - - - - Paths 2 - - - - - - - - - -
void path2 (gameState *g) // Wizard Path (Increase ? Stat)
{   
    std::cout << "Current Path: 2" << std::endl;

    if (g->dialogue2 == true) // With Dialogue
    {
        cinignore();

        std::cout << "< ??? >" << std::endl;
        std::cout << "\"What brings thee in this parts?\"" << std::endl;
        contin();
        std::cout << "< " << g->p.name << " >" << std::endl;
        std::cout << "\"Who are you?\"" << std::endl;
        contin();
        std::cout << "< Wizard >" << std::endl;
        std::cout << "\"I am but a humble wizard\"" << std::endl;
        contin();
        std::cout << "< " << g->p.name << " >" << std::endl;
        std::cout << "\"What is a wizard doing here?\"" << std::endl;
        contin();
        std::cout << "< Wizard >" << std::endl;
        std::cout << "\"You need not know of it\"" << std::endl;
        std::cout << "\"Instead I can offer some services if you do me a favor\"" << std::endl;
        contin();
        std::cout << "< " << g->p.name << " >" << std::endl;
        std::cout << "\"What favor?\"" << std::endl;
        contin();
        std::cout << "< Wizard >" << std::endl;
        std::cout << "\"In the room the next of this one\"" << std::endl;
        std::cout << "\"There's a pesky skeleton ruining my garden\"" << std::endl;
        std::cout << "\"Kill it in exchange for a reward\"" << std::endl;
        contin();
        std::cout << "< " << g->p.name << " >" << std::endl;
        int move1 = accept();
        
        space();

        g->dialogue2 = false;

        if (move1 == 1) // Accepted Wizards Offer
        {
            cinignore();

            g->qWizard.active = true; // Activates The Wizards Quest

            std::cout << "< Wizard >" << std::endl;
            std::cout << "\"I knew I could count on you!\"" << std::endl;
            contin();

            // Continue Path 2_2 Here With Wizard Quest
            std::cout << "Entering The Next Room. . ." << std::endl;
            contin();

            path2_2(g); // Enter With Quest Value 1 (With Quest)
        }
        else if (move1 == 0) // Declined Wizard Offer
        {
            cinignore();

            g->qWizard.active = false;

            std::cout << "< Wizard >" << std::endl;
            std::cout << "\"Eh? Your loss then\"" << std::endl;
            std::cout << "\"Come to me again if you ever change your mind\"" << std::endl;
            contin();
            
            optionsPath2_2(g);
        }
    }
    else if (g->dialogue2 == false) // No Dialogue
    { 
        optionsPath2_2(g);  
    }

}

void path2_2 (gameState *g)
{
    std::cout << "Current Path: 2-2" << std::endl;

    if (g->qWizard.active == true)
    {
        std::cout << "Wizard Quest: Active" << std::endl;
    }
    else if (g->qWizard.active == false)
    {
        std::cout << "Wizard Quest: Inactive" << std::endl;
    }

    contin();

    skeleton skeleton;

    if (g->numOfSkeletons > 0)
    {
        std::cout << "< " << skeleton.name << " >" << std::endl;
        std::cout << "(Bones Crackling)" << std::endl;
        contin();
        std::cout << "# You See " << g->numOfSkeletons << " Skeleton Scattered In The Wizards Garden" << std::endl;
    }

    int move1;
    g->numOfSkeletons;

    while (1)
    {
        if (g->numOfSkeletons == 3)
        {
            std::cout << "[1] Attack Skeleton 1" << std::endl;
            std::cout << "[2] Attack Skeleton 2" << std::endl;
            std::cout << "[3] Attack Skeleton 3" << std::endl;            
            std::cout << "[4] Turn Back" << std::endl;


        }
        else if (g->numOfSkeletons == 2)
        {
            std::cout << "[1] Attack Skeleton 1" << std::endl;
            std::cout << "[2] Attack Skeleton 2" << std::endl;
            std::cout << "[3] Turn Back" << std::endl;
        }
        else if (g->numOfSkeletons == 1)
        {
            std::cout << "[1] Attack Skeleton 1" << std::endl;
            std::cout << "[2] Turn Back" << std::endl;
        }
        else 
        {
            std::cout << "[1] Turn Back" << std::endl;
        }
        std::cout << "Next Move: ";
        std::cin >> move1;
    

        int result;



        // Adaptive Choices (Changes Everytime A Skeleton Is Killed)
        if (g->numOfSkeletons == 3)
        {
            if (move1 == 1)
            {
                std::cout << "Attacking Skeleton 1" << std::endl; 
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                }
                else 
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 2)
            {
                std::cout << "Attacking Skeleton 2" << std::endl;
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                }
                else
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 3)
            {
                std::cout << "Attacking Skeleton 3" << std::endl;
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                }
            }
            else if (move1 == 4)
            {
                cinignore();
                contin(); 
                std::cout << "Turning Back. . ." << std::endl;
                contin();

                g->dialogue2 = false;
                path2(g);
                break;

            }
        }
        else if (g->numOfSkeletons == 2)
        {
            if (move1 == 1)
            {
                std::cout << "Attacking Skeleton 1" << std::endl; 
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                }
                else 
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 2)
            {
                std::cout << "Attacking Skeleton 2" << std::endl;
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    g->numOfSkeletons--;
                    skeleton.resetStats();
                }
                else
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 3)
            {
                cinignore();
                contin(); 
                std::cout << "Turning Back. . ." << std::endl;
                contin();

                g->dialogue2 = false;
                path2(g);
                break;
            }
        }
        else if (g->numOfSkeletons == 1)
        {
            if (move1 == 1)
            {
                std::cout << "Attacking Skeleton 1" << std::endl; 
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    g->numOfSkeletons--;
                    skeleton.resetStats();

                    if (g->qWizard.active)
                    {
                        g->qWizard.finished = true;
                    }
                }
                else 
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 2)
            {
                cinignore();
                contin(); 
                std::cout << "Turning Back. . ." << std::endl;
                contin();

                g->dialogue2 = false;
                path2(g);
                break;
            }
        }
        else 
        {
            if (move1 == 1)
            {
                cinignore();
                contin(); 
                std::cout << "Turning Back. . ." << std::endl;
                contin();

                g->dialogue2 = false;
                path2(g);
                break;
            }
            else 
            {
                std::cout << "Error" << std::endl;
            }
        }
    }
}

void optionsPath2_2 (gameState *g)
{
    int move1;
    
    std::cout << "[1] Continue to next room " << std::endl;
    std::cout << "[2] Talk to Wizard" << std::endl;
    std::cout << "[3] Go back" << std::endl;
    
    std::cout << "Next Move: ";
    std::cin >> move1;
    
    if (move1 == 1)
    {
        cinignore();
        std::cout << "Entering next room. . ." << std::endl;
        contin();

        path2_2(g);
    }
    else if (move1 == 2)
    {
        if (g->qWizard.finished == true)
        {
            cinignore();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "What Do You Need?" << std::endl;
            contin();
            std::cout << "< " << g->p.name << " >" << std::endl;
            std::cout << "So About The Reward?" << std::endl;
            contin();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "Ohh.. Right" << std::endl;
            contin();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "Done Already?" << std::endl;
            contin();
            std::cout << "< " << g->p.name << " >" << std::endl;
            std::cout << "Yup" << std::endl;
            contin();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "In Return I Can Make You Stronger!" << std::endl;
            contin();
            std::cout << "< " << g->p.name << " >" << std::endl;
            std::cout << "Stronger? How?" << std::endl;
            contin();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "Well It's Quite Easy Actually" << std::endl;
            std::cout << "All I Need Is A Few Gold And I Can Magically Enhance You" << std::endl;
            std::cout << "Try Using The Gold You Got From Those Skeletons" << std::endl;
            contin();

            statUp(g);

            
            // Add statup Function Here
            // Consider Making This A One Time Section (Dialogue & Free statUp's)
        }
        else
        {
            int move2;

            std::cout << "Approaching the Wizard. . ." << std::endl;
            
            if (g->qWizard.active == true) // If The Quest Is Currently Active
            {
                cinignore();
                std::cout << "< Wizard >" << std::endl;
                std::cout << "\"You have Skeletons To Kill\"" << std::endl;
                std::cout << "\"Stop Wasting Time Here!\"" << std::endl;
                contin();

                path2(g);
            }
            else if (g->qWizard.active == false)
            {
                std::cout << "< Wizard >" << std::endl;
                std::cout << "\"Ready To Take My Offer?\"" << std::endl;
                yn();
                std::cin >> move2;

                if (move2 == 1) // If Yes. Accept Wizard Quest
                {
                    cinignore();

                    std::cout << "< Wizard >" << std::endl;
                    std::cout << "\"Nice!\"" << std::endl;
                    std::cout << "\"Now Go Slay Me Some Skeletons\"" << std::endl;
                    contin();

                    std::cout << "Entering Next Room. . ." << std::endl;
                    contin();

                    g->qWizard.active = true; // Activates Quest

                    path2_2(g);
                }
                else if (move2 == 2)
                {
                    std::cout << "< Wizard >" << std::endl;
                    std::cout << "\"Stop Wasting My Time Then!\"" << std::endl;

                    path2(g);
                }
                else if (std::cin.fail())
                {
                    validnum();
                }
                else
                {
                    std::cout << "Invalid Number" << std::endl;
                }
            }
        }

    }                                                           
    else if (move1 == 3)
    {
        std::cout << "Here we are again. . ." << std::endl;
        path0(g);
    }
    else if (std::cin.fail())
    {
        validnum();    
    }
    else
    {
        std::cout << "Invalid Number" << std::endl;
    }   
}