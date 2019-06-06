//
//  main.cpp
//  finalP_XMLparser
//
//  Created by Kevin Gonzalez on 5/23/19.
//  Copyright © 2019 Kevin Gonzalez. All rights reserved.
//  Description: This program will find the questions and answers and return them as a string vector as well as get the qid numbers, 
//                  aid numbers and store them in a 2D array.

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include <typeinfo>


using namespace std;



string fileName = "basic-brad.plist";
//string fileName = "basic.plist";
//string fileName = "Wizard npc.plist";
//string fileName = "builder_template2.plist";
//string fileName = "bradandrachel.plist";
//string fileName = "brad.plist";
//string fileName = "brachel.plist";

//Precondition: make sure plist file is in the right directory
//Postcondition: returns the Questions in a string vector
vector<string> parseQ(string plist);

//Precondition: make sure plist file is in the right directory
//Postcondition: returns the Answer in a string vector
vector<string> parseA(string plist);

//Precondition: make sure plist file is in the right directory
//Postcondition: stores the qid links and aid links in a 2D array. each value has been incremented by 1.
void parseLink(string array[][2], string plist);


int main()
{
    string arr[999][2];
    vector<string> v = parseQ(fileName);
    //parseLink(arr, fileName);
    for(auto i : v)
    {
        cout << i << endl;
    }
    
    return 0;
}

//Precondition: make sure plist file is in the right directory
//Postcondition: returns the Questions in a string vector
vector<string> parseQ(string plist)
{
    using namespace std;
    ifstream plistExtract; //open the plist file in this function
    string part, temp;
    int posOfString, sizeToDelete = 9;
    vector<string> stringOfQs;
    plistExtract.open(plist);
    if(plistExtract.fail())
    {
        cout << "This file does not exist." << endl;
    }
    
    smatch matches;
    regex reg("<string>([\\w\\s\\w\?]+)</string>"); // this one is for the questions.
    regex bradEx("<string>brad_[\\w[:d:]]+</string>");
    while(!plistExtract.eof())
    {
        getline(plistExtract, part);
        
        sregex_iterator currentMatch(part.begin(), part.end(), reg); // stores the first match
        
        sregex_iterator lastMatch; // checks if there's any more matches
        
        // While the current match doesn't equal the last
        while(currentMatch != lastMatch)
        {
            smatch match = *currentMatch; // this user a dereferenced operator. similar to a call by reference.
            if (match.str()=="<string>Brad</string>"||match.str()=="<string>Type</string>"||match.str()=="<string>Wizard npc</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.classifier.cl.Provider</string>"||match.str()=="<string>Toss</string>"||match.str()=="<string>Negative</string>"||match.str()=="<string>Neutral</string>"||match.str()=="<string>Emotion</string>"||match.str()=="<string>Up</string>"||match.str()=="<string>Flat</string>"||match.str()=="<string>Down</string>"||match.str()=="<string>Tone</string>"||match.str()=="<string>Clear dialog state and then set it to given tokens</string>"||match.str()=="<string>Add tokens replacing existing category values</string>"||match.str()=="<string>Add tokens for undefined categories to the state, do not change the existing categories</string>"||match.str()=="<string>Do not change dialog state</string>"||match.str()=="<string>Dialog State</string>"||match.str()=="<string>Development</string>"||match.str()=="<string>Training</string>"||match.str()=="<string>Wizard</string>"||match.str()=="<string>groovy</string>"||match.str()=="<string>brad_I4QC</string>"||match.str()=="<string>brad_X73H</string>"||match.str()=="<string>brad_6I0Y</string>"||match.str()=="<string>brad_MMZM</string>"||match.str()=="<string>brad_XVZL</string>"||match.str()=="<string>brad_CA4Y</string>"||match.str()=="<string>brad_3B8I</string>"||match.str()=="<string>brad_GKFY</string>"||match.str()=="<string>brad_52DS</string>"||match.str()=="<string>brad_65YK</string>"||match.str()=="<string>speaker</string>"||match.str()=="<string>type</string>"||match.str()=="<string>unknown</string>"||match.str()=="<string>conceal</string>"||match.str()=="<string>repeat</string>"||match.str()=="<string>opaque</string>"||match.str()=="<string>toss</string>"||match.str()=="<string>emotion</string>"||match.str()=="<string>negative</string>"||match.str()=="<string>neutral</string>"||match.str()=="<string>tone</string>"||match.str()=="<string>up</string>"||match.str()=="<string>flat</string>"||match.str()=="<string>down</string>"||match.str()=="<string>set</string>"||match.str()=="<string>reset</string>"||match.str()=="<string>add</string>"||match.str()=="<string>none</string>"||match.str()=="<string>train_test</string>"||match.str()=="<string>dev</string>"||match.str()=="<string>train</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.Person</string>"||match.str()=="<string>npc</string>"||match.str()=="<string>edu.usc.ict.npc.editor.dialog.script.ScriptableDialogManager</string>"||match.str()=="<string>0</string>"||match.str()=="<string>Type</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.processor.text.TextProcessorProvider</string>"||match.str()=="<string>brad_KWDI</string>"||match.str()=="<string>brad_FDPL</string>"||match.str()=="<string>brad_EYNX</string>"||match.str()=="<string>brad_HDDW</string>"||match.str()=="<string>brad_G1AK</string>"||match.str()=="<string>brad_A4L6</string>"||match.str()=="<string>brad_0MDA</string>"||match.str()=="<string>brad_LZT7</string>"||match.str()=="<string>brad_HGKB</string>"||match.str()=="<string>brad_5AOW</string>"||match.str()=="<string>brad_KNDX</string>"||match.str()=="<string>brad_7CPF</string>"||match.str()=="<string>brad_L7PO</string>"||match.str()=="<string>brad_5GEL</string>"||match.str()=="<string>brad_VHH6</string>"||match.str()=="<string>brad_X84U</string>"||match.str()=="<string>brad_Y1A5</string>"||match.str()=="<string>brad_57OW</string>"||match.str()=="<string>brad_X2D6</string>"||match.str()=="<string>brad_RY9C</string>"||match.str()=="<string>brad_W56J</string>"||match.str()=="<string>brad_Y502</string>"||match.str()=="<string>brad_W1F3</string>"||match.str()=="<string>brad_XILF</string>"||match.str()=="<string>brad_VAHF</string>"||match.str()=="<string>brad_TU60</string>"||match.str()=="<string>brad_CUCU</string>"||match.str()=="<string>brad_7KW0</string>"||match.str()=="<string>brad_1WHR</string>"||match.str()=="<string>brad_H74Z</string>"||match.str()=="<string>brad_Q09I</string>"||match.str()=="<string>brad_34H8</string>"||match.str()=="<string>brad_DZD5</string>"||match.str()=="<string>brad_17QF</string>"||match.str()=="<string>brad_8DOU</string>"||match.str()=="<string>brad_LTXY</string>"||match.str()=="<string>_please_repeat_that_repeat_</string>"||match.str()=="<string>brad_script_repeat</string>"||match.str()=="<string>brad_cansayagain</string>"||match.str()=="<string>brad_onemoretime</string>"||match.str()=="<string>brad_sorrycatch</string>"||match.str()=="<string>brad_haveagoodday</string>"||match.str()=="<string>brad_goodbye</string>"||match.str()=="<string>brad_good</string>"||match.str()=="<string>brad_quitewell</string>"||match.str()=="<string>brad_hibrad</string>"||match.str()=="<string>brad_name</string>"||match.str()=="<string>brad_fullname</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.report.ReportGeneratorProvider</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.processor.text.TextProcessorProvider</string>"||match.str()=="<string>dialogState</string>"||match.str()=="<string>test</string>"||match.str()=="<string>Test</string>"||match.str()=="<string>Can you say that again?</string>"||match.str()=="<string>Could you try saying that one more time?</string>"||match.str()=="<string>0.7401220271802874 0.8923064360283753 -3.2767529487609863</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.EvaluationFrameworkProvider$MeanFScoreEvaluationFramework</string>"||match.str()=="<string>Train/Test</string>"||match.str()=="<string>Anybody-69</string>"||match.str()=="<string>Anybody-68</string>"||match.str()=="<string>Anybody-67</string>"||match.str()=="<string>Anybody-66</string>"||match.str()=="<string>Anybody-65</string>"||match.str()=="<string>Anybody-64</string>"||match.str()=="<string>Anybody-63</string>"||match.str()=="<string>Anybody-62</string>"||match.str()=="<string>Anybody-61</string>"||match.str()=="<string>Anybody-59</string>"||match.str()=="<string>Anybody-60</string>"||match.str()=="<string>Anybody-57</string>"||match.str()=="<string>Anybody-58</string>"||match.str()=="<string>Anybody-55</string>"||match.str()=="<string>Anybody-56</string>"||match.str()=="<string>Anybody-53</string>"||match.str()=="<string>Anybody-54</string>"||match.str()=="<string>Anybody-51</string>"||match.str()=="<string>Anybody-52</string>"||match.str()=="<string>Anybody-49</string>"||match.str()=="<string>Anybody-50</string>"||match.str()=="<string>Anybody-47</string>"||match.str()=="<string>Anybody-48</string>"||match.str()=="<string>Anybody-45</string>"||match.str()=="<string>Anybody-46</string>"||match.str()=="<string>Anybody-43</string>"||match.str()=="<string>Anybody-44</string>"||match.str()=="<string>Anybody-41</string>"||match.str()=="<string>Anybody-42</string>"||match.str()=="<string>Anybody-40</string>"||match.str()=="<string>Anybody-39</string>"||match.str()=="<string>Anybody-37</string>"||match.str()=="<string>Anybody-38</string>"||match.str()=="<string>Anybody-35</string>"||match.str()=="<string>Anybody-36</string>"||match.str()=="<string>Anybody-33</string>"||match.str()=="<string>Anybody-34</string>"||match.str()=="<string>Anybody-31</string>"||match.str()=="<string>Anybody-32</string>"||match.str()=="<string>Anybody-29</string>"||match.str()=="<string>Anybody-30</string>"||match.str()=="<string>Anybody-27</string>"||match.str()=="<string>Anybody-28</string>"||match.str()=="<string>Anybody-25</string>"||match.str()=="<string>Anybody-26</string>"||match.str()=="<string>Anybody-23</string>"||match.str()=="<string>Anybody-24</string>"||match.str()=="<string>Anybody-21</string>"||match.str()=="<string>Anybody-22</string>"||match.str()=="<string>Anybody-19</string>"||match.str()=="<string>Anybody-20</string>"||match.str()=="<string>Anybody-17</string>"||match.str()=="<string>Anybody-18</string>"||match.str()=="<string>Anybody-15</string>"||match.str()=="<string>Anybody-16</string>"||match.str()=="<string>Anybody-14</string>"||match.str()=="<string>Anybody-12</string>"||match.str()=="<string>Anybody-13</string>"||match.str()=="<string>Anybody-11</string>"||match.str()=="<string>Anybody-10</string>"||match.str()=="<string>Anybody-9</string>"||match.str()=="<string>Anybody-8</string>"||match.str()=="<string>Anybody-7</string>"||match.str()=="<string>Anybody-6</string>"||match.str()=="<string>Anybody-5</string>"||match.str()=="<string>Anybody-4</string>"||match.str()=="<string>Anybody-3</string>"||match.str()=="<string>Anybody-2</string>"||match.str()=="<string>Anybody-1</string>"||match.str()=="<string>Anybody-69</string>"||match.str()=="<string>Anybody-70</string>"||match.str()=="<string>Anybody-72</string>"||match.str()=="<string>Anybody-71</string>"||match.str()=="<string>Anybody-73</string>"||match.str()=="<string>Anybody-79</string>"||match.str()=="<string>Anybody-74</string>"||match.str()=="<string>Anybody-78</string>"||match.str()=="<string>Anybody-75</string>"||match.str()=="<string>Anybody-77</string>"||match.str()=="<string>Anybody-76</string>")
            {
                //do nothing
            }
            else
            {
                temp = match.str().erase(0,8);
                posOfString = (int)temp.find("</string>");
                temp =  temp.erase(posOfString, sizeToDelete);
                stringOfQs.push_back(temp);
            }
            
            currentMatch++;
        }
        
        //cout << endl;
        
    }
    plistExtract.close(); // close plist file in function
    return stringOfQs;
}

//Precondition: make sure plist file is in the right directory
//Postcondition: returns the Answer in a string vector
vector<string> parseA(string plist)
{
    using namespace std;
    ifstream plistExtract; //open the plist file in this function
    string part, temp;
    int posOfString, sizeToDelete = 9;
    vector<string> stringOfAs;
    plistExtract.open(plist);
    if(plistExtract.fail())
    {
        cout << "This file does not exist." << endl;
    }
    
    smatch matches;
    regex reg("<string>([\\w[:punct:],\\s.][^\\?]+)</string>"); // this one is for the questions.
    regex bradEx("<string>brad_[\\w[:d:]]+</string>");
    while(!plistExtract.eof())
    {
        getline(plistExtract, part);
        
        sregex_iterator currentMatch(part.begin(), part.end(), reg); // stores the first match
        
        sregex_iterator lastMatch; // checks if there's any more matches
        
        while(currentMatch != lastMatch)
        {
            smatch match = *currentMatch;
            if (match.str()=="<string>Brad</string>"||match.str()=="<string>Type</string>"||match.str()=="<string>Wizard npc</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.classifier.cl.Provider</string>"||match.str()=="<string>Toss</string>"||match.str()=="<string>Negative</string>"||match.str()=="<string>Neutral</string>"||match.str()=="<string>Emotion</string>"||match.str()=="<string>Up</string>"||match.str()=="<string>Flat</string>"||match.str()=="<string>Down</string>"||match.str()=="<string>Tone</string>"||match.str()=="<string>Clear dialog state and then set it to given tokens</string>"||match.str()=="<string>Add tokens replacing existing category values</string>"||match.str()=="<string>Add tokens for undefined categories to the state, do not change the existing categories</string>"||match.str()=="<string>Do not change dialog state</string>"||match.str()=="<string>Dialog State</string>"||match.str()=="<string>Development</string>"||match.str()=="<string>Training</string>"||match.str()=="<string>Wizard</string>"||match.str()=="<string>groovy</string>"||match.str()=="<string>brad_I4QC</string>"||match.str()=="<string>brad_X73H</string>"||match.str()=="<string>brad_6I0Y</string>"||match.str()=="<string>brad_MMZM</string>"||match.str()=="<string>brad_XVZL</string>"||match.str()=="<string>brad_CA4Y</string>"||match.str()=="<string>brad_3B8I</string>"||match.str()=="<string>brad_GKFY</string>"||match.str()=="<string>brad_52DS</string>"||match.str()=="<string>brad_65YK</string>"||match.str()=="<string>speaker</string>"||match.str()=="<string>type</string>"||match.str()=="<string>unknown</string>"||match.str()=="<string>conceal</string>"||match.str()=="<string>repeat</string>"||match.str()=="<string>opaque</string>"||match.str()=="<string>toss</string>"||match.str()=="<string>emotion</string>"||match.str()=="<string>negative</string>"||match.str()=="<string>neutral</string>"||match.str()=="<string>tone</string>"||match.str()=="<string>up</string>"||match.str()=="<string>flat</string>"||match.str()=="<string>down</string>"||match.str()=="<string>set</string>"||match.str()=="<string>reset</string>"||match.str()=="<string>add</string>"||match.str()=="<string>none</string>"||match.str()=="<string>train_test</string>"||match.str()=="<string>dev</string>"||match.str()=="<string>train</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.Person</string>"||match.str()=="<string>npc</string>"||match.str()=="<string>edu.usc.ict.npc.editor.dialog.script.ScriptableDialogManager</string>"||match.str()=="<string>0</string>"||match.str()=="<string>Type</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.processor.text.TextProcessorProvider</string>"||match.str()=="<string>brad_KWDI</string>"||match.str()=="<string>brad_FDPL</string>"||match.str()=="<string>brad_EYNX</string>"||match.str()=="<string>brad_HDDW</string>"||match.str()=="<string>brad_G1AK</string>"||match.str()=="<string>brad_A4L6</string>"||match.str()=="<string>brad_0MDA</string>"||match.str()=="<string>brad_LZT7</string>"||match.str()=="<string>brad_HGKB</string>"||match.str()=="<string>brad_5AOW</string>"||match.str()=="<string>brad_KNDX</string>"||match.str()=="<string>brad_7CPF</string>"||match.str()=="<string>brad_L7PO</string>"||match.str()=="<string>brad_5GEL</string>"||match.str()=="<string>brad_VHH6</string>"||match.str()=="<string>brad_X84U</string>"||match.str()=="<string>brad_Y1A5</string>"||match.str()=="<string>brad_57OW</string>"||match.str()=="<string>brad_X2D6</string>"||match.str()=="<string>brad_RY9C</string>"||match.str()=="<string>brad_W56J</string>"||match.str()=="<string>brad_Y502</string>"||match.str()=="<string>brad_W1F3</string>"||match.str()=="<string>brad_XILF</string>"||match.str()=="<string>brad_VAHF</string>"||match.str()=="<string>brad_TU60</string>"||match.str()=="<string>brad_CUCU</string>"||match.str()=="<string>brad_7KW0</string>"||match.str()=="<string>brad_1WHR</string>"||match.str()=="<string>brad_H74Z</string>"||match.str()=="<string>brad_Q09I</string>"||match.str()=="<string>brad_34H8</string>"||match.str()=="<string>brad_DZD5</string>"||match.str()=="<string>brad_17QF</string>"||match.str()=="<string>brad_8DOU</string>"||match.str()=="<string>brad_LTXY</string>"||match.str()=="<string>_please_repeat_that_repeat_</string>"||match.str()=="<string>brad_script_repeat</string>"||match.str()=="<string>brad_cansayagain</string>"||match.str()=="<string>brad_onemoretime</string>"||match.str()=="<string>brad_sorrycatch</string>"||match.str()=="<string>brad_haveagoodday</string>"||match.str()=="<string>brad_goodbye</string>"||match.str()=="<string>brad_good</string>"||match.str()=="<string>brad_quitewell</string>"||match.str()=="<string>brad_hibrad</string>"||match.str()=="<string>brad_name</string>"||match.str()=="<string>brad_fullname</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.report.ReportGeneratorProvider</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.processor.text.TextProcessorProvider</string>"||match.str()=="<string>dialogState</string>"||match.str()=="<string>test</string>"||match.str()=="<string>Test</string>"||match.str()=="<string>Can you say that again?</string>"||match.str()=="<string>Could you try saying that one more time?</string>"||match.str()=="<string>0.7401220271802874 0.8923064360283753 -3.2767529487609863</string>"||match.str()=="<string>edu.usc.ict.npc.editor.model.EvaluationFrameworkProvider$MeanFScoreEvaluationFramework</string>"||match.str()=="<string>Train/Test</string>"||match.str()=="<string>Anybody-69</string>"||match.str()=="<string>Anybody-68</string>"||match.str()=="<string>Anybody-67</string>"||match.str()=="<string>Anybody-66</string>"||match.str()=="<string>Anybody-65</string>"||match.str()=="<string>Anybody-64</string>"||match.str()=="<string>Anybody-63</string>"||match.str()=="<string>Anybody-62</string>"||match.str()=="<string>Anybody-61</string>"||match.str()=="<string>Anybody-59</string>"||match.str()=="<string>Anybody-60</string>"||match.str()=="<string>Anybody-57</string>"||match.str()=="<string>Anybody-58</string>"||match.str()=="<string>Anybody-55</string>"||match.str()=="<string>Anybody-56</string>"||match.str()=="<string>Anybody-53</string>"||match.str()=="<string>Anybody-54</string>"||match.str()=="<string>Anybody-51</string>"||match.str()=="<string>Anybody-52</string>"||match.str()=="<string>Anybody-49</string>"||match.str()=="<string>Anybody-50</string>"||match.str()=="<string>Anybody-47</string>"||match.str()=="<string>Anybody-48</string>"||match.str()=="<string>Anybody-45</string>"||match.str()=="<string>Anybody-46</string>"||match.str()=="<string>Anybody-43</string>"||match.str()=="<string>Anybody-44</string>"||match.str()=="<string>Anybody-41</string>"||match.str()=="<string>Anybody-42</string>"||match.str()=="<string>Anybody-40</string>"||match.str()=="<string>Anybody-39</string>"||match.str()=="<string>Anybody-37</string>"||match.str()=="<string>Anybody-38</string>"||match.str()=="<string>Anybody-35</string>"||match.str()=="<string>Anybody-36</string>"||match.str()=="<string>Anybody-33</string>"||match.str()=="<string>Anybody-34</string>"||match.str()=="<string>Anybody-31</string>"||match.str()=="<string>Anybody-32</string>"||match.str()=="<string>Anybody-29</string>"||match.str()=="<string>Anybody-30</string>"||match.str()=="<string>Anybody-27</string>"||match.str()=="<string>Anybody-28</string>"||match.str()=="<string>Anybody-25</string>"||match.str()=="<string>Anybody-26</string>"||match.str()=="<string>Anybody-23</string>"||match.str()=="<string>Anybody-24</string>"||match.str()=="<string>Anybody-21</string>"||match.str()=="<string>Anybody-22</string>"||match.str()=="<string>Anybody-19</string>"||match.str()=="<string>Anybody-20</string>"||match.str()=="<string>Anybody-17</string>"||match.str()=="<string>Anybody-18</string>"||match.str()=="<string>Anybody-15</string>"||match.str()=="<string>Anybody-16</string>"||match.str()=="<string>Anybody-14</string>"||match.str()=="<string>Anybody-12</string>"||match.str()=="<string>Anybody-13</string>"||match.str()=="<string>Anybody-11</string>"||match.str()=="<string>Anybody-10</string>"||match.str()=="<string>Anybody-9</string>"||match.str()=="<string>Anybody-8</string>"||match.str()=="<string>Anybody-7</string>"||match.str()=="<string>Anybody-6</string>"||match.str()=="<string>Anybody-5</string>"||match.str()=="<string>Anybody-4</string>"||match.str()=="<string>Anybody-3</string>"||match.str()=="<string>Anybody-2</string>"||match.str()=="<string>Anybody-1</string>"||match.str()=="<string>What knowledge do I need to have before taking CS classes?</string>"||match.str()=="<string>What are the requirements for taking CS02?</string>"||match.str()=="<string>What is the difference between Computer Science and Computer Engineering?</string>"||match.str()=="<string>What are some job opportunities for Computer Science?</string>"||match.str()=="<string>What are some programming languages in Computer Science?</string>"||match.str()=="<string>What is Computer Science?</string>"||match.str()=="<string>Should I study Computer Science?</string>"||match.str()=="<string>How can I succeed in Computer Science?</string>"||match.str()=="<string>How can I transfer as a Computer Science Major?</string>"||match.str()=="<string>How long does it take for me to transfer?</string>"||match.str()=="<string>What is your favorite food?</string>"||match.str()=="<string>What is your favorite color?</string>"||match.str()=="<string>How can I apply for scholarships?</string>"||match.str()=="<string>What are some CS(Computer Science) classes that I can take at PCC?</string>"||match.str()=="<string>Where can I get free tutoring sections?</string>"||match.str()=="<string>Where can I do group studying?</string>"||match.str()=="<string>Anybody-1</string>"||match.str()=="<string>Where can I study and do my homework?</string>"||match.str()=="<string>What is your advices for the classes at PCC?</string>"||match.str()=="<string>How can I transfer to a 4-years university?</string>"||match.str()=="<string>What is your advices for me at PCC?</string>"||match.str()=="<string>How can I contact the financial aid office at PCC?</string>"||match.str()=="<string>Who are you?</string>"||match.str()=="<string>How is the weather at PCC?</string>"||match.str()=="<string>How much does it cost to study at PCC?</string>"||match.str()=="<string>Anybody-1</string>"||match.str()=="<string>How can I apply to PCC?</string>"||match.str()=="<string>Anybody-1</string>"||match.str()=="<string>Where can I register for classes ?</string>"||match.str()=="<string>How much is the tuition fee at PCC?</string>"||match.str()=="<string>What supports can I get from admission office?</string>"||match.str()=="<string>How do I get to the admissions office?</string>"||match.str()=="<string>Where is the admission office located?</string>"||match.str()=="<string>Where is financial aid office at PCC ?</string>"||match.str()=="<string>Where is the admissions office?</string>"||match.str()=="<string>What kind of financial aids can I get at PCC?</string>"||match.str()=="<string>Where is the admin office?</string>"||match.str()=="<string>Where is PCC admission office?</string>"||match.str()=="<string>How can I contact the admission office at PCC?</string>"||match.str()=="<string>What supports can I get from financial aid offices?</string>"||match.str()=="<string>What's your address?</string>"||match.str()=="<string>What is the current address?</string>"||match.str()=="<string>Where is this college located?</string>"||match.str()=="<string>Anybody-1</string>"||match.str()=="<string>Where is Pasadena City College?</string>"||match.str()=="<string>Anybody-1</string>"||match.str()=="<string>What's happening?</string>"||match.str()=="<string>What's up?</string>"||match.str()=="<string>How are you doing today?</string>"||match.str()=="<string>How are you doing?</string>"||match.str()=="<string>How are you?</string>"||match.str()=="<string>What's your name?</string>"||match.str()=="<string>What is your name, sir?</string>"||match.str()=="<string>What is your name?</string>"||match.str()=="<string>What is PCC?</string>"||match.str()=="<string>What math courses do I need to take for Computer Science major?</string>"||match.str()=="<string>How is Computer Science Professor at PCC?</string>"||match.str()=="<string>How can I contact Computer Science Department?</string>"||match.str()=="<string>Where is Computer Science Department?</string>"||match.str()=="<string>What can I learn from CS002?</string>"||match.str()=="<string>What is CS002?</string>"||match.str()=="<string>What are some tips for coding?</string>"||match.str()=="<string>What are some good programs or Clubs for Computer Science students?</string>"||match.str()=="<<string>What is Python?</string>"||match.str()=="<string>What are some facts about Computer Science students?</string>"||match.str()=="<string>Should I take CS courses or CIS courses?</string>"||match.str()=="<string>What CS courses do I need to take for Computer Science major?</string>"||match.str()=="<string>Anybody-69</string>"||match.str()=="<string>Anybody-70</string>"||match.str()=="<string>Anybody-72</string>"||match.str()=="<string>Anybody-71</string>"||match.str()=="<string>Anybody-73</string>"||match.str()=="<string>Anybody-79</string>"||match.str()=="<string>Anybody-74</string>"||match.str()=="<string>Anybody-78</string>"||match.str()=="<string>Anybody-75</string>"||match.str()=="<string>Anybody-77</string>"||match.str()=="<string>Anybody-76</string>")
            {
                //do nothing
            }
            else
            {
                temp = match.str().erase(0,8);
                posOfString = (int)temp.find("</string>");
                temp =  temp.erase(posOfString, sizeToDelete);
                stringOfAs.push_back(temp);
            }
            
            currentMatch++;
        }
        
        //cout << endl;
        
    }
    plistExtract.close(); // close plist file in function
    return stringOfAs;
}

//Precondition: make sure plist file is in the right directory
//Postcondition: stores the qid links and aid links in a 2D array. each value has been incremented by 1.
void parseLink(string array[][2], string plist)
{
    using namespace std;
    ifstream plistExtract; //open the plist file in this function
    string part, temp;
    int posOfString, sizeToDelete = 10, counter = 0, strToInt;
    plistExtract.open(plist);
    if(plistExtract.fail())
    {
        cout << "This file does not exist." << endl;
    }
    
    smatch matches;
    regex regQid("(<key>qid</key>)"); // locates the question link
    regex regAid("(<key>aid</key>)"); // locates the answer link
    while(!plistExtract.eof())
    {
        getline(plistExtract, part);
        
        sregex_iterator currentMatch(part.begin(), part.end(), regQid); // stores the first match
        
        sregex_iterator lastMatch; // checks if there's any more matches
        
        while(currentMatch != lastMatch)
        {
            smatch match = *currentMatch;
            getline(plistExtract, part);
            
            temp = part.erase(0,9);
            
            posOfString = (int)temp.find("</integer>");
            
            temp =  temp.erase(posOfString, sizeToDelete);
            strToInt = stoi(temp)+1;
            stringstream convertIntBackToString;
            convertIntBackToString << strToInt;
            array[counter][0] = convertIntBackToString.str();
            currentMatch++;
            counter++;
        }
    }
    plistExtract.close();
    
    counter=0;
    plistExtract.open(plist);
    while(!plistExtract.eof())
    {
        getline(plistExtract, part);
        
        sregex_iterator currentMatch(part.begin(), part.end(), regAid); // stores the first match
        
        sregex_iterator lastMatch; // checks if there's any more matches
        
        while(currentMatch != lastMatch)
        {
            smatch match = *currentMatch;
            getline(plistExtract, part);
            
            temp = part.erase(0,9);
            
            posOfString = (int)temp.find("</integer>");
            
            temp =  temp.erase(posOfString, sizeToDelete);
            //cout << temp << endl;
            strToInt = stoi(temp)+1;
            stringstream convertIntBackToString;
            convertIntBackToString << strToInt;
            array[counter][1] = convertIntBackToString.str();
            currentMatch++;
            counter++;
        }
    }
    for(int i=0;i<70;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout << array[i][j];
        }
        cout << endl;
    }
    plistExtract.close();
}
