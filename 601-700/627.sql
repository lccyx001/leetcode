/* 给定一个 salary 表，如下所示，有 m = 男性 和 f = 女性 的值。
交换所有的 f 和 m 值（例如，将所有 f 值更改为 m，反之亦然）。
要求只使用一个更新（Update）语句，并且没有中间的临时表。
注意，您必只能写一个 Update 语句，请不要编写任何 Select 语句。
例如：
| id | name | sex | salary |
|----|------|-----|--------|
| 1  | A    | m   | 2500   |
| 2  | B    | f   | 1500   |
| 3  | C    | m   | 5500   |
| 4  | D    | f   | 500    |
运行你所编写的更新语句之后，将会得到以下表:
| id | name | sex | salary |
|----|------|-----|--------|
| 1  | A    | f   | 2500   |
| 2  | B    | m   | 1500   |
| 3  | C    | f   | 5500   |
| 4  | D    | m   | 500    |
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-salary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。 */
UPDATE salary
SET
    sex = CASE sex
        WHEN 'm' THEN 'f'
        ELSE 'm'
    END;
-- 单纯考语法，无聊。。。