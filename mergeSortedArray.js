function mergeSortedArray(array1, array2){
   const mergedArray = [];
   let array1Item = array1[0];
   let array2Item = array2[0];

   let i = 1;
   let j = 1;

   while(array1Item || array2Item){
      if(array2Item == undefined || array1Item < array2Item){
         mergedArray.push(array1Item);
         array1Item = array1[i];
         i++;
      }else{
         mergedArray.push(array2Item);
         array2Item = array2[j];
         j++;
      }
   }
   
   return mergedArray;
}

let arra1 = [4, 4, 4, 4, 7, 9, 50];
let arra2 = [4, 5, 6, 7];

console.log(mergeSortedArray(arra1, arra2));
