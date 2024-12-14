#include <iostream>
#include <vector>

std::vector<int> getConcatenation(std::vector<int>& nums);

int main(int argc, char* argv[])
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    //std::cout << "Before function\n";
    std::cout << "My function returns: ";
    std::vector<int> ans = getConcatenation(nums);
    //std::cout << "After function\n";
    for(int i = 0; i < ans.size(); i++)
    {
        std::cout << "ans[" << i << "]: " << ans[i] << std::endl;
    }
	return 0;
}

//std::vector<int> getConcatenation(std::vector<int>& nums)
//{
//    std::vector<int> ans;
//    ans.resize(2 * nums.size());
//    for(int i = 0; i < nums.size(); i++)
//    {
//        std::cout << "First loop, i = " << i << std::endl;
//        ans[i] = nums[i];
//    }
//    for(int i = 0; i < nums.size(); i++)
//    {
//        std::cout << "Second loop, i = " << i << std::endl;
//        ans[i + nums.size()] = nums[i];
//    }
//    return ans;
//}

std::vector<int> getConcatenation(std::vector<int>& nums)
{
    std::vector<int> ans;

    ans = nums;
    ans = ans + nums;
    return ans;
}